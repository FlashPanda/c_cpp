#include <list>
#include <future>
#include <thread>
#include <atomic>
#include <memory>
#include <algorithm>

template <typename T>
struct sorter   // sorter class
{
    struct chunk_to_sort
    {
        std::list<T> data;
        std::promise<std::list<T>> promise;
    };
    thread_safe_stack<chunk_to_sort> chunks;    // the stack of unsorted chunks
    std::vector<std::thread> threads;   // the set of threads
    const size_t max_thread_count;
    std::atomic<bool> end_of_data;

    sorter():
        max_thread_count(std::thread::hardware_concurrency() - 1),
        end_of_data(false) {}

    ~sorter() 
    {
        end_of_data = true; // 5
        for (size_t i = 0; i < threads.size(); ++i)
            threads[i].join();  // 6
    }

    void try_sort_chunk()
    {
        std::shared_ptr<chunk_to_sort> chunk = chunks.pop();    // pop a chunk from the stack
        if (chunk)
            sort_chunk(chunk);  // sort the popped chunk
    }

    // the main work is done here
    std::list<T> do_sort(std::list<T>& chunk_data)
    {
        if (chunk_data.empty())
            return chunk_data;

        std::list<T> result;
        result.splice(result.begin(), chunk_data, chunk_data.begin());
        const T& partition_val = *result.begin();
        // do the usual partitioning of the data
        typename std::list<T>::iterator divide_point = 
            std::partition(chunk_data.begin(), chunk_data.end(), 
                           [&](T const& val) {return val < partition_val;});
        chunk_to_sort new_lower_chunk;
        new_lower_chunk.data.splice(new_lower_chunk.data.end(),
                                    chunk_data, chunk_data.begin(),
                                    divide_point);
        std::future<std::list<T>> new_lower = new_lower_chunk.promise.get_future();
        chunks.push(std::move(new_lower_chunk));    // push the new chunk onto the stack
        if (threads.size() < max_thread_count)  // If we still have processor to spare, create a new thread
            threads.push_back(std::thread(&sorter<T>::sort_thread, this));
        std::list<T> new_higher(do_sort(chunk_data));
        result.splice(result.end(), new_higher);
        // The lower chunk might be handled by another thread, we have to wait for it to be ready.
        while(new_lower.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
            // In case this is the only thread or all the others are already busy
            // try to process chunks from this thread while we're waiting.
            try_sort_chunk();

        result.splice(result.begin(), new_lower.get());
        return result;
    }

    void sort_chunk(const std::shared_ptr<chunk_to_sort>& chunk)
    {
        // Storing the value in the promise, ready to be picked up
        // by the thread that posted the chunk on the stack
        chunk->promise.set_value(do_sort(chunk->data));
    }
    void sort_thread()
    {
        while(!end_of_data) // if the end_of_data flatg isn't set.
        {
            try_sort_chunk();   // try to sort the chunks off the stack

            // Give other threads a change to put some more work on the stack
            std::this_thread::yield();
        }
    }
};

template <typename T>
std::list<T> parallel_quick_sort(std::list<T> input)    // 19
{
    if (input.empty())
        return input;
    sorter<T> s;
    return s.do_sort(input);    // 20
}


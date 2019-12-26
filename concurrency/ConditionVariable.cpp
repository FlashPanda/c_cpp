/**
 * From https://en.cppreference.com/w/cpp/thread/condition_variable
 * */
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});     // If the condition is not satified, the mutex will be unlocked.

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed \n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again.(see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main()
{
    using namespace std::chrono_literals;
    std::thread worker (worker_thread);

    data = "Example data";
    // send data to the worker thread
    std::this_thread::sleep_for(1s);
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();    // notify a thread to check its condition

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';
    worker.join();
}
#include <iostream>
#include <memory>	// shared_ptr所在路径
#include <thread>
#include <chrono>
#include <mutex>

struct Base {
	Base () { std::cout << " 调用Base的构造函数\n"; }
	// 注意：非虚构造函数在这里是没问题的。
	~Base() {std::cout << " 调用Base的析构函数\n";}
};

struct Derived : public Base {
	Derived () { std::cout << "调用Derived的构造函数\n"; }
	~Derived () { std::cout << "调用Derived的析构函数\n"; }
};

void thr (std::shared_ptr<Base> p) {
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::shared_ptr <Base> lp = p;
	
	{
		static std::mutex io_mutex;
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "local pointer in a thread:" << std::endl
				  << "   lp.get() = " << lp.get()
				  << ", lp.use_count() = " << lp.use_count () << "\n";
	}
}

int main() {
	std::shared_ptr <Base> p = std::make_shared<Derived> ();
	
	std::cout << "创建一个共享的Derived（作为一个到Base的指针）" << std::endl
			  << "   p.get() = " << p.get()
			  << ", p.use_count() = " << p.use_count () << std::endl;
			  
	std::thread t1 (thr, p), t2 (thr, p), t3 (thr, p);
	p.reset();	// 释放主函数中的引用
	std::cout << "共享的拥有关系在三个线程之间并且释放" << std::endl;
	std::cout << "main函数中的拥有权：" << std::endl
			  << "  p.get() = " << p.get()
			  << ", p.use_count() = " << p.use_count() << std::endl;
			  
	t1.join(); t2.join(); t3.join();
	std::cout << "所有的线程都完成，最后一个删除掉Derived的指针\n";
	
	std::getchar();
}
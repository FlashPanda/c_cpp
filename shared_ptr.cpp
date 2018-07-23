#include <memory>	// shared_ptr
#include <iostream>
#include <cassert>

int main () {
	std::shared_ptr<int> sp (new int (10));		// 一个指向整数的shared_ptr
	assert (sp.unique());						// sp是这个内存空间的唯一持有者
	std::cout << "sp的值是：" << *sp << std::endl;	// 输出

	std::shared_ptr<int> sp2 = sp;					// 现在又多出来一个持有者
	assert (sp == sp2 && sp.use_count() == 2);	// 现在是两个持有者，指针值是一样的。
	std::cout << "sp的值是：" << *sp << "，引用计数是：" << sp.use_count() << std::endl;

	*sp2 = 100;									// 将数值该成100
	assert (*sp == 100);						// 这是成立的
	std::cout << "sp的值是：" << *sp << "，引用计数是：" << sp.use_count() << std::endl;

	sp.reset ();								// sp不指向100了
	assert (sp == nullptr);						// 这是成立的
	std::cout << "sp的地址是：" << sp << "，sp1的值是：" << *sp2 << "，引用计数是" << sp2.use_count() << std::endl;

	return 0;
}

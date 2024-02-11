#include <iostream>
using namespace std;
//
//
//int main()
//{
//	//C  函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//	
//	free(p1);
//	free(p3);
//	
//	//C++ 操作符
//	int* p2 = new int;//随机值
//	//int* p2 = new int(10);  //申请一个int4个字节的空间，初始化为10
//	int* p4 = new int[10];    //申请10个int的40个字节的空间
//
//	delete p2;
//	delete[] p4;
//	return 0;
//}



//既然已经有了malloc和free，new和delete的意义何在

//1. 对于内置类型，效果一样
//2. 对于自定义类型，效果就不一样了。malloc只申请空间，new申请空间+构造函数初始化
//		free只释放空间，delete析构函数+释放空间
// class MyClass
// {
// public:
// 	MyClass()
// 	{
// 		_a = 10;
// 		cout << "MyClass" << endl;
// 	}
// 	~MyClass()
// 	{
// 		cout << "~MyClass" << endl;
// 	}
// 	void test()
// 	{
// 		cout << "test" << endl;
// 	}

// private:
// 	int _a;
// };
// int main()
// {
// 	int* p1 = new int;
// 	int* p2 = (int*)malloc(sizeof(int));
// 	//对于内置类型int，p1和p2效果一样


// 	// 自定义类型
// 	MyClass* p4 = (MyClass*)malloc(sizeof(MyClass));//申请空间
// 	MyClass* p3 = new MyClass;	//申请空间+构造函数初始化
// 	free(p4);		//释放空间
// 	delete p3;		//析构函数+释放空间
// 	return 0;
// }


//operator new 和 malloc 区别是什么
//这两种使用方式一样，处理错误的方式不一样
//class A
//{
//public:
//	A()
//	{
//		_a = 10;
//		cout << "A" << endl;
//	}
//	~A()
//	{
//		cout << "~A" << endl;
//	}
//	void test()
//	{
//		cout << "test" << endl;
//	}
//	
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)operator new(sizeof(A));
//
//	//operator new 和 malloc 区别是什么
//	//这两种使用方式一样，处理错误的方式不一样
//
//	size_t size = 2;
//	A* p3 =(A*) malloc(size * 1024 * 1024*1024);
//	cout << p3 << endl;  //申请出来的p3地址是0，申请失败，malloc返回0地址。因为申请的空间太大了，堆的内存比栈大
//
//	//A* p4 = (A*)operator new(size * 1024 * 1024 * 1024);
//	//cout << p4 << endl;  //失败抛异常 （面向对象处理错的方式）
//
//	try
//	{
//		void* p5 = operator new(size * 1024 * 1024 * 1024);
//		//申请空间失败抛异常bad_allocation
//		cout << p5 << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


/*
总结：
malloc （void *）malloc（int size）
operator new ==> malloc+失败抛异常
new			==> operator new+构造函数
new比起malloc不一样的地方：1.使用构造函数初始化，2.失败抛异常
delete 比起 free不一样的地方：1.调用析构函数进行清理
operator delete 和free没有区别：因为释放空间失败直接终止进程.是为了跟operator new成对出现
new[] 和 delete[] 是连续空间
new T[N]实际上是调用operator new[]函数,operator new[]中调用operator new函数完成对N个对象空间的申请，在申请的空间上执行N次构造函数
delete[]  实际上在释放的对象空间上执行N次析构函数，完成对N个对象的资源清理，operator delete[]调用operator delete函数释放空间
*/


//operator new 默认是全局函数
//如何定制专属operator new函数呢？
//class A
//{
//public:
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<A>().allocate(1);//内存池
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<A>().deallocate((A*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//private:
//	int a;
//
//};
//int main()
//{
//	A* p = new A;
//	delete p;
//	return 0;
//}



//定位new

//class A
//{
//public:
//	A(int a = 0) :_a(a)
//	{
//		cout << "A()" << endl;
//
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//
//};
//int main()
//{
//	A* p = new A;
//	delete p;
//
//	//如何模拟上面的行为
//	//显式调用了A的构造函数和析构函数
//	A* p2 = (A*)operator new(sizeof(A));
//	//对已经存在的一块空间调用构造函数进行初始化，定位new/replacement new
//	new(p2)A(10);  //new(空间的指针)类型(参数)
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}



//内存泄漏
//
//int main()
//{
//	char* p = new char[1024 * 1024 * 1024];
//	//忘记释放p指向的空间，就是内存泄露
//	//危害：长期运行的程序（游戏服务），出现内存泄漏危害很大，或者设备的内存本身很小，也有危害
//
//	return 0;
//}



//如何在堆区申请4G大小的内存
//
//int main()
//{
//	try
//	{
//		size_t size = 4;
//		void* p = new char[size * 1024 * 1024 * 1024];
//		cout << p << endl;
//		//在32位进行下申请不出来，在62位进程就可以申请成功
//		//32 位寻址空间只有 4GB 大小，于是 32 位应用程序（进程）最大只能用到 4GB 的内存。
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

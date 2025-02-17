#include<iostream>

using namespace std;

/*
C++没有gc(垃圾回收)，new/malloc等等出来的资源，是需要我们去手动释放，
1、忘记释放
2、发生异常安全问题
	new/malloc/lock
	fun();//throw 异常
	delete/free/unlock
最终都导致资源的泄露
*/

//int Div()
//{
//	int a = 1, b = 0;
//	if (b == 0)
//		throw invalid_argument("除零错误");
//	return a / b;
//}
//void f1()
//{
//	int* i = new int;//new失败也会抛异常，当有多个new时，再通过重新抛异常就很麻烦，通过智能指针能更好的解决
//	try
//	{
//		Div();
//	}
//	catch (exception& e)
//	{
//		delete i;
//		throw e;
//	}
//	catch (...)
//	{
//		delete i;
//		throw; //如果是捕捉所有类型的异常，这里用throw来再抛异常
//	}
//	delete i;
//}
//int main()
//{
//	try {
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}



/*
RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术。
在对象构造时获取资源，接着控制对资源的访问使之在对象的生命周期内始终保持有效，最后在对象析构的时候释放资源。
借此，我们实际上把管理一份资源的责任托管给了一个对象。
这种做法有两大好处：
不需要显式地释放资源;
采用这种方式，对象所需的资源在其生命期内始终保持有效.
*/
//RAII是一种托管资源的思想，智能指针是依靠这种RAII实现的，unique_lock / lock_guard 也是
//智能指针，管理资源释放
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr):_ptr(ptr)
//	{ }
//
//	//无论是函数正常结束，还是抛异常，都会导致SmartPtr对象的生命周期到了以后，调用析构函数
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			cout << "释放ptr" << endl;
//			delete _ptr;
// 			_ptr = nullptr;
//		}
//	}
//	//像指针一样使用
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//int Div()
//{
//	int a = 1, b = 1;
//	if (b == 0)
//		throw invalid_argument("除零错误");
//	return a / b;
//}
//void f1()
//{
//	int* i = new int;//new失败也会抛异常，当有多个new时，再通过重新抛异常就很麻烦，通过智能指针能更好的解决	
//	SmartPtr<int> sp(i); 
//	//无论是函数正常结束，还是抛异常，都会导致sp对象的生命周期到了以后，调用析构函数
//	//RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的简单技术。
//	Div();
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//
//	SmartPtr<pair<int, int>> sp2(new pair<int, int>);
//	sp2->first = 20;
//	sp2->second = 30;
//	cout << sp2->first << endl;
//}
//int main()
//{
//	try {
//		f1();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}


//智能指针的坑

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr):_ptr(ptr)
//	{ }
//
//	//无论是函数正常结束，还是抛异常，都会导致SmartPtr对象的生命周期到了以后，调用析构函数
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			cout << "释放ptr" << endl;
//			delete _ptr;
// 			_ptr = nullptr;
//		}
//	}
//	//像指针一样使用
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//int main()
//{
//	int* p1 = new int;
//	int* p2 = p1;//目的是让两个指针指向同一块内存
//
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2 = sp1;
//	//两个指针指向同一块内存，导致重复释放同一块资源。
//	//不能用深拷贝，因为深拷贝的话导致两个指针不能指向同一块资源
//	//智能指针只是受人托管资源空间，可以访问空间
//	//模拟的是原生指针行为，只是比原生指针多的是可以在生命周期结束时释放资源
//	/*
//	3种解决方式：
//	1、管理权转移
//	2、防拷贝
//	3、引用计数
//	C++98：auto_ptr，管理权转移
//	C++11：unique_ptr，防拷贝
//	C++11：shared_ptr，引用计数的共享拷贝
//			循环引用的问题，又需要weak_ptr来解决
//	*/
//	return 0;
//}


//namespace cr
//{
//	//C++98：auto_ptr，管理权转移,早期设计缺陷，一般公司都明令禁止使用它
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr) :_ptr(ptr)
//		{
//		}
//		auto_ptr(auto_ptr<T>& ap) :_ptr(ap._ptr)
//		{
//			// 管理权转移,把原来的智能指针置空,访问就会报错，
//			ap._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)
//		{
//			if (this != &ap)
//			{
//				if (_ptr)
//				{
//					delete _ptr;
//				}
//				_ptr = ap._ptr;
//				ap._ptr = nullptr;
//			}
//			return *this;
//		}
//		~auto_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "释放auto_ptr" << endl;
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//
//	//C++11：unique_ptr，防拷贝，简单粗暴，推荐使用
//	//缺陷:如果有需要拷贝的场景，他就没法使用
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr):_ptr(ptr)
//		{ }
//		//防拷贝
//		unique_ptr(const unique_ptr<T>& up) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;
//
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "释放unique_ptr" << endl;
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr) :_ptr(ptr),_pcount(new int(1))
//		{
//		}
//
//		shared_ptr(shared_ptr<T>& sp)
//		{
//			_ptr = sp._ptr;
//			_pcount = sp._pcount;
//			++(*_pcount);
//		}
//		shared_ptr<T>& operator=(shared_ptr<T>& sp)
//		{
//			if (this != &sp)
//			{
//				//赋值拷贝时，要注意原来是否有资源,但不能根据_ptr来判断，因为有可能是拷贝构造的，会导致重复释放
//				if (--(*_pcount)==0) 	
//				{
//					delete _ptr;
//					delete _pcount;
//				}
//				_ptr = sp._ptr;
//				_pcount = sp._pcount;
//				++(*_pcount);
//			}
//			return *this;
//		}
//		~shared_ptr()
//		{
//			//cout << *_pcount;
//			if (_ptr && --(*_pcount) ==0 )
//			{
//				cout << "释放shared_ptr" << endl;
//				delete _ptr;
//				_ptr = nullptr;
//				delete _pcount;
//				_pcount = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	
//		//记录有多少个对象一起共享管理资源，最后一个析构释放资源
//		//static int _count; //static不能处理多个对象
//		//int _count;//使用int不能同时管理不同对象的count
//		int* _pcount;//综上，要使用指针类型的
//	};
//}
//
//int main()
//{
//	cr::auto_ptr<int> ap(new int);
//	cr::auto_ptr<int> ap1 = ap;
//	//*ap = 1;//缺陷:ap1 = ap场景下ap就悬空了，访问就会报错，如果不熟悉他的特性就会被坑
//
//	cr::unique_ptr<int> up(new int);
//	//cr::unique_ptr<int> up1(up); //防拷贝与赋值拷贝
//	//cr::unique_ptr<int> up1 = up;
//
//	cr::shared_ptr<int> sp(new int);
//	cr::shared_ptr<int> sp1(sp);
//	cr::shared_ptr<int> sp2 = sp;
//	sp2 = sp;
//
//	return 0;
//}


//shared_ptr共享指针的拷贝构造时线程安全问题
//shared_ptr是否是线程安全的，
//答: 注意这里问题的shared_ptr对象拷贝和析构++ / --引用计数是否是安全的，库的实现中是安全的，
//#include<thread>
//#include<mutex>
//namespace cr
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr) :_ptr(ptr), _pcount(new int(1)),_pmtx(new mutex)
//		{
//		}
//
//		shared_ptr(const shared_ptr<T>& sp)
//		{
//			_ptr = sp._ptr;
//			_pcount = sp._pcount;
//			_pmtx = sp._pmtx;
//			add_count();
//		}
//		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//		{
//			if (this != &sp)
//			{
//				release();//先释放原来的资源
//
//				_ptr = sp._ptr;
//				_pcount = sp._pcount;
//				_pmtx = sp._pmtx;
//				add_count();
//			}
//			return *this;
//		}
//		void add_count()
//		{
//			_pmtx->lock();
//			++(*_pcount);
//			_pmtx->unlock();
//		}
//
//		int use_count()
//		{
//			return *_pcount;
//		}
//		T* get_ptr()const
//		{
//			return _ptr;
//		}
//		~shared_ptr()
//		{
//			release();
//		}
//		void release()
//		{
//			bool flag = false;
//			_pmtx->lock();
//			if (--(*_pcount) == 0)
//			{
//				//cout << "释放shared_ptr" << endl;
//				if (_ptr)
//				{
//					delete _ptr;
//					_ptr = nullptr;
//				}
//				delete _pcount;
//				_pcount = nullptr;
//				flag = true;
//			}
//			_pmtx->unlock();
//			if (flag==true)
//			{
//				delete _pmtx; //不能在_pmtx->unlock()之前释放_pmtx
//				_pmtx = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//
//		//记录有多少个对象一起共享管理资源，最后一个析构释放资源
//		//static int _count; //static不能处理多个对象
//		//int _count;//使用int不能同时管理不同对象的count
//		int* _pcount;//综上，要使用指针类型的
//		mutex* _pmtx;
//	};
//
//	//为了解决循环引用的问题，C++11有个弱指针(专门来解决shared_ptr的问题)：weak_ptr
//	//严格来说weak_ptr不是智能指针，因为他没有RAII资源管理机制
//	//专门解决shared_ptr的循环引用问题
//	template<class T>
//	class weak_ptr
//	{
//	public:
//		weak_ptr() = default;
//		weak_ptr(T* ptr) :_ptr(ptr)
//		{
//		}
//		weak_ptr(const cr::shared_ptr<T>& sp) :_ptr(sp.get_ptr())
//		{
//		}
//		weak_ptr<T>& operator=(const cr::shared_ptr<T>& sp)
//		{
//			_ptr = sp.get_ptr();
//			return *this;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//}
//
////C++11:shared_ptr
////引用计数，可以拷贝
////缺陷 : 循环引用
////struct ListNode
////{
////	int _data;
////	cr::shared_ptr<ListNode> _prev;
////	cr::shared_ptr<ListNode> _next;
////	ListNode():_data(0),_prev(nullptr),_next(nullptr)
////	{
////	}
////	~ListNode() { cout << "~ListNode()" << endl; }
////};
//
//
//struct ListNode
//{
//	int _data;
//	//cr::shared_ptr<ListNode> _prev;
//	//cr::shared_ptr<ListNode> _next;
//
//	cr::weak_ptr<ListNode> _prev; //循环引用解决方式：不使用计数
//	cr::weak_ptr<ListNode> _next;
//	ListNode() :_data(0), _prev(nullptr), _next(nullptr)
//	{
//	}
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	/*cr::shared_ptr<int> sp(new int);
//	int n = 10000;
//	thread t1([&]() {
//		for (int i = 0; i < n; ++i)
//		{
//			cr::shared_ptr<int> sp2(sp);
//			sp2 = sp;
//		}
//		});
//	thread t2([&]() {
//		for (int i = 0; i < n; ++i)
//		{
//			cr::shared_ptr<int> sp3(sp);
//			sp3 = sp;
//		}
//		});
//
//	t1.join();
//	t2.join();*/
//
//	//循环引用
//	/*cr::shared_ptr<ListNode> node1(new ListNode);
//	cr::shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;*/
//	/*
//	循环引用分析：
//		1. node1和node2两个智能指针对象指向两个节点，引用计数变成1，我们不需要手动delete。
//		2. node1的_next指向node2，node2的_prev指向node1，引用计数变成2。
//		3. node1和node2析构，引用计数减到1，但是_next还指向下一个节点。但是_prev还指向上一个节点。
//		4. 也就是说_next析构了，node2就释放了。
//		5. 也就是说_prev析构了，node1就释放了。
//		6. 但是_next属于node2的成员，node1释放了，_next才会析构，而node1由_prev管理，
//		_prev属于node2成员，所以这就叫循环引用，谁也不会释放。
//	*/
//	//通过调试一步步可以捋清楚过程
//
//	//循环引用解决方式：ListNode里使用weak_ptr，不使用计数
//	//前提是你知道这里有循环引用
//	cr::shared_ptr<ListNode> node1(new ListNode);
//	cr::shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	return 0;
//}

/*
智能指针的历史
C++没有gc(垃圾回收期)，申请的资源需要释放是一个问题，尤其是碰到异常安全问题，特别难处理
稍不注意就会出现内存泄露。内存泄露到导致程序可用的内存越来越少，程序中很多操作都是需要内存的。
那么会导致程序基本处于瘫痪状态，所以我们尽量要杜绝内存泄露问题。
所以就发展处了基于RAII思想的智能指针，但是由于没有gc的坑，引入智能指针
而智能指针经历了十几年发展的坑爹血泪史

第一阶段:
C++98中首次推出了auto_ptr，但是auto_ptr的设计存在重大缺陷，不建议使用

第二阶段:
C++官方在接下来的十几年中没有作为，有一帮牛人就生气了，觉得C++库太简陋了，所以自己搞一个非官方社区，写了一个库叫boost。
boost库中就重新写了智能指针。注意boost库中其他很多其他实现的东西
scoped_ptr/scoped_array		防拷贝版本
shared_ptr/shared_array		引用计数版本
weak_ptr

scoped_ptr /shared_ptr析构函数用的delete
array的析构函数用的delete[]，重载operator[]

第三阶段:
C++11中引入智能指针,参考boost的实现，微改了一下。 其实C++11其他类似右值引用移动语句等等也是参考boost
unique_ptr(参考的scoped_ptr搞的)
shared_ptr
weak_ptr
*/


//C++11 shared_ptr里没有operator[]
//定制删除器(传一个实现释放方式仿函数对象进去给智能指针)
//class A
//{
//public:
//	A() = default;
//	A(const int& t):_a(t)
//	{ }
//private:
//	int _a;
//};
//
//template<class T>
//struct DeleteArray
//{
//	void operator()(T* arr)
//	{
//		cout << "DeleteArray" << endl;
//		delete[] arr;
//	}
//	T* _arr;
//};
//
//struct Free
//{
//	void operator()(void* p)
//	{
//		cout << "Free" << endl;
//		free(p);
//	}
//	
//};
//struct Fclose
//{
//	void operator()(FILE*  f)
//	{
//		cout << "Fclose" << endl;
//		fclose(f);
//	}
//};
//int main()
//{
//	std::shared_ptr<A> sp1(new A);
//	std::shared_ptr<A> sp2(new A[10], DeleteArray<A>());
//	std::shared_ptr<A> sp3((A*)malloc(sizeof(A)*10),Free());
//	std::shared_ptr<FILE> sp4(fopen("text.c","w"),Fclose());
//
//	return 0;
//}


//智能指针是RAII思想的一种应用的体现
//本质RAII就是借助构造函数和析构函数来搞事情，因为构造函数和析构函数的特点都是自动调用
//使用RAII思想实现一个锁管理守卫
#include<mutex>
template<class Lock>
class LockGuard
{
public:
	LockGuard(Lock& lock):_lk(lock)
	{
		_lk.lock();
	}
	~LockGuard()
	{
		cout << "~LockGuard()解锁" << endl;
		_lk.unlock();
	}
	LockGuard(LockGuard<Lock>& lock) = delete;
	LockGuard<Lock>& operator=(LockGuard<Lock>& lock) = delete;
private:
	Lock& _lk;//这里必须用引用，因为mutex不支持拷贝
};

//void f()
//{
//	mutex mtx;
//	mtx.lock(); //这里没有使用锁管理守卫，如果下面抛异常，就会跳过unlock，导致死锁
//	//抛异常
//	mtx.unlock();// lock()和unlock()要成对使用，不能重复上锁和解锁
//}
void f()
{
	mutex mtx;
	LockGuard<mutex> lg(mtx);

	//抛异常
	
	//mtx.unlock();
	// lock()和unlock()要成对使用，不能重复上锁和解锁，
	// 在LockGuard里已经使用了unlock，出了作用域，就析构自动调用unlock
}
int main()
{
	try {
		f();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
	/*
	C++中的lock_guard和unique_lock两种互斥锁管理工具，它们都用于实现线程安全的互斥访问。
	lock_guard提供简单的自动锁定和解锁，适用于基本的互斥保护；
	unique_lock则更加灵活，支持手动解锁和更多高级功能，如锁超时。
	*/
	mutex mtx,g_mtx;
	lock_guard<mutex> lg(mtx);//构造时自动上锁
	//lock_guard不支持手动解锁
	
	unique_lock<mutex> ul(g_mtx);//构造时自动上锁
	//ul.lock(); //unique_lock支持手动lock与unlock
	ul.unlock();
	
	return 0;
}


/*
内存泄露
1、什么是内存泄露?
	内存泄露一般一般是我们申请了资源，这个资源我不用了，但是忘记释放，或者因为异常安全等问题没有释放。
2、内存泄露的危害是什么?
	如果我们申请了内存没有释放，如果进程正常结束，那么这个内存也会释放。
	一般程序碰到内存泄露，重启后就ok了。
	长期运行，不能随便重启的程序，碰到内存泄露危害非常大,比如操作系统，比如服务器上的服务。
	危害是:这些程序长期运行，不用的内存没有释放，内存泄露,
	可用内存越来越少，导致服务很多操作失败(因为容器存数据，打开文件，创建套接字，发送数据等等都是需要内存的)

ps:一般后台服务器开始，如果出现内存泄露，都是事故。轻则扣奖金，涨薪短期受限，重则开除。

3、如何解决内存泄露相关问题
	a、写C/C++代码时小心谨慎一点。
	b、不好处理的地方多用智能指针等等去管理。(事前预防)
	c、如果怀疑存在内存泄露，或者已经出现，可以使用内存泄露工具去检测。(事后解决)
	valgrind是一个Linux下的强大内存泄露工具
*/

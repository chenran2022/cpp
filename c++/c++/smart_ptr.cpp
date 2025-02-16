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
#include<thread>
#include<mutex>
namespace cr
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr) :_ptr(ptr), _pcount(new int(1)),_pmtx(new mutex)
		{
		}

		shared_ptr(const shared_ptr<T>& sp)
		{
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_pmtx = sp._pmtx;
			add_count();
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				release();//先释放原来的资源

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;
				add_count();
			}
			return *this;
		}
		void add_count()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		int use_count()
		{
			return *_pcount;
		}

		~shared_ptr()
		{
			release();
		}
		void release()
		{

			bool flag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				cout << "释放shared_ptr" << endl;
				if (_ptr)
				{
					delete _ptr;
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();
			if (flag==true)
			{
				delete _pmtx; //不能在_pmtx->unlock()之前释放_pmtx
				_pmtx = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;

		//记录有多少个对象一起共享管理资源，最后一个析构释放资源
		//static int _count; //static不能处理多个对象
		//int _count;//使用int不能同时管理不同对象的count
		int* _pcount;//综上，要使用指针类型的
		mutex* _pmtx;
	};
}

int main()
{
	cr::shared_ptr<int> sp(new int);
	int n = 10000;
	thread t1([&]() {
		for (int i = 0; i < n; ++i)
		{
			cr::shared_ptr<int> sp2(sp);
			sp2 = sp;
		}
		});
	thread t2([&]() {
		for (int i = 0; i < n; ++i)
		{
			cr::shared_ptr<int> sp3(sp);
			sp3 = sp;
		}
		});

	t1.join();
	t2.join();

	return 0;
}

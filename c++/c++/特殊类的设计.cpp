#include<iostream>
using namespace std;

/*
1.请设计一个类，不能被拷贝
拷贝只会放生在两个场景中: 拷贝构造函数以及赋值运算符重载，
因此想要让一个类禁止拷贝只需让该类不能调用拷贝构造函数以及赋值运算符重载即可。
*/
class CopyBan
{
public:
	/*C++11扩展delete的用法，delete除了释放new申请的资源外，
	如果在默认成员函数后跟上= delete，表示让编译器删除掉该默认成员函数。*/
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
private:
	/*C++98
	将拷贝构造函数与赋值运算符重载只声明不定义，并且将其访问权限设置为私有即可*/
	CopyBan(const CopyBan&);
	CopyBan& operator=(const CopyBan&);
};


/*
2.设计一个类，只能在堆上创建对象(如果需要在堆上创建对象，要么使用new运算符，要么使用malloc系列函数。)
实现方式：
	1. 将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
	2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
*/
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	// C++11
	HeapOnly(const HeapOnly&) = delete;
private:
	HeapOnly() {}
	// C++98
	// 1.只声明,不实现。
	// 2.声明成私有
	HeapOnly(const HeapOnly&);
};

/*
3. 请设计一个类，只能在栈上创建对象
方法一：同上将构造函数私有化，然后设计静态方法创建对象返回即可。
*/
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();
	}
	// 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
	// StackOnly obj = StackOnly::CreateObj();
	// StackOnly* ptr3 = new StackOnly(obj);
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	StackOnly()
		:_a(0)
	{
	}
private:
	int _a;
};
//方法二：仅把new和delete删掉
//这种方案存在一定程序缺陷，无法阻止在数据段(静态区)创建对象。所以要把构造函数私有化
//static StackOnly so;
class StackOnly
{
public:
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;

private:
	int _a;
};

//4. 请设计一个类，不能被继承
// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{
	}
};
//C++11: final关键字，final修饰类，表示该类不能被继承。
class A final
{
	// ....
};

//int main()
//{
//	NonInherit ni = NonInherit::GetInstance();
//	static StackOnly so;
//	return 0;
//}

//之前已经学过一些设计模式
//迭代器模式 -- 基于面向对象三大特性之一的 封装设计出来的，用一个迭代器类封装以后,不暴露容器的结构的情况下，统一的方式访问修改容器中的数据。
//适配器模式 --体现的是一种复用
//还有一些常见的设计模式如 : 工厂模式、装饰器模式、观察者模式、单例模式.

//5.请设计一个类，只能创建一个对象(单例模式)
/*
单例模式：
一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，
并提供一个访问它的全局访问点，该实例被所有程序模块共享。
*/
#include<mutex>

//懒汉模式
//懒汉模式 -- 第一次获取对象时，再创建对象
namespace lazy_man
{
	class Singleton
	{
	public:
		//使用static是为了可以通过类名去访问，static成员函数只能访问static成员变量
		/*
		static Singleton* GetInstance()
		{
			//存在多线程安全问题，当多个线程同时第一次访问这里，会同时new出对象，导致内存泄漏和多个对象
			if (_pinst==nullptr)
			{
				return new Singleton;
			}
			return _pinst; //返回同一个空间
		}
		*/
		/*
		static Singleton* GetInstance()
		{

			{
				//_mtx.lock();//如果使用这种方式，当中间new时出现异常，就会造成死锁

				unique_lock<mutex> ul(_mtx); //添加一个{}局部域，出了作用域，自动调用析构函数并解锁
				//这里只需要第一次进来进行加锁，后面就不需要再加锁了，消耗资源
				if (_pinst == nullptr)
				{
					return new Singleton;
				}

				//_mtx.unlock();
			}



			return _pinst; //返回同一个空间
		}
		*/
		static Singleton* GetInstance()
		{

			//双检查：防止对象创建好了之后，再加锁
			if (_pinst == nullptr)
			{
				//_mtx.lock();//如果使用这种方式，当中间new时出现异常，就会造成死锁

				unique_lock<mutex> ul(_mtx); //添加一个{}局部域，出了作用域，自动调用析构函数并解锁
				//这里只需要第一次进来进行加锁，后面就不需要再加锁了，消耗资源
				if (_pinst == nullptr)
				{
					return new Singleton;
				}

				//_mtx.unlock();
			}

			return _pinst; //返回同一个空间
		}

		//因为此类对象全局下只有一个，且一直在使用，没必要释放它
		//如果需要手动释放，就定义static void DelInstance()
		static void DelInstance()
		{
			unique_lock<mutex> ul(_mtx);
			delete _pinst;
			_pinst = nullptr;
		}
		Singleton(const Singleton& sg) = delete;
		Singleton& operator=(const Singleton& sg) = delete;
	private:
		Singleton() {};
		static Singleton* _pinst;//类内声明，类外定义
		static mutex _mtx;
	};
	Singleton* Singleton::_pinst = nullptr;
	mutex Singleton::_mtx;
	//1、如果要手动释放单例对象，可以调用DelInstance
	//2、如果需要程序结束时，正常释放单例对象，可以加入下面的设计
	class GC
	{
	public:
		~GC()
		{
			Singleton::DelInstance();
		}
	};
	static GC gc;
	//定义一个全局静态变量GC，当main函数结束后，会自动调用gc的析构函数
	//因为main函数已经结束了，所以就不存在多线程，DelInstance()就不需要加锁了
}

//饿汉模式 -- 一开始(main函数之前)就创建对象
namespace hungry_man
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_pinst;
		}
		Singleton(const Singleton& sg) = delete;
		Singleton& operator=(const Singleton& sg) = delete;
	private:
		Singleton() {};
		static Singleton _pinst;//类内声明，类外定义
		
	};	
	Singleton Singleton::_pinst;
	//static对象是在main函数之前创建的，这会只有主线程，所以不存在线程安全。
	//static对象在创建时无法保证创建顺序，是由编译器决定的
}

/*
总结对比一下饿汉和懒汉的区别
1、懒汉模式需要考虑线程安全和释放的问题，实现相对更复杂，饿汉模式不存在以上问题，实现简单
2、懒汉是一种懒加载模式，当需要时再初始化创建对象，不会影响程序的启动。
	饿汉模式则相反，程序启动阶段就创建初始化实例对象，会导致程序启动慢，影响体验。
3、如果有多个单例类，假设有依赖关系(B依赖A)，要求A单例先创建初始化，B单例再创建初始化，
那么就不能饿汉，因为无法保证static对象创建初始化顺序，这时用懒汉我们就可以手动控制。
4、如果在对象里需要创建一个线程或者使用到动态库，不能使用饿汉模式，
	因为在main函数之前不能创建线程，动态库是在启动程序时加载的，不一定加载完成，所以不能使用饿汉
	而懒汉模式单例对象是在main函数之后创建，可以创建线程和使用动态库

总结一下:实际中懒汉模式还是更实用一些
*/
int main()
{
	//Singleton copy(*Singleton::GetInstance());不能进行拷贝构造，Singleton(const Singleton& sg) = delete;

	return 0;
}

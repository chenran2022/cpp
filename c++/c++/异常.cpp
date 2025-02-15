#include<iostream>
#include<vector>
#include<string>
using namespace std;

//什么是异常:异常是面向对象语法处理错误一种方式
/*
C语言传统的处理错误的方式:
传统的错误处理机制：
1. 终止程序，如assert/exit，缺陷：用户难以接受。如发生内存错误，除0错误时就会终止程序。
2. 返回错误码，缺陷：需要程序员自己去查找对应的错误。如系统的很多库的接口函数API都是通过把错误码放到errno中，表示错误
实际中C语言基本都是使用返回错误码的方式处理错误，部分情况下使用终止程序处理非常严重的错误。

传统的处理错误的缺陷:
a、如果一个函数是用过返回值拿数据，发生错误时很难处理，
T& operator[](int index)
{
	// 如果index超出的容器范围，如何返回?
}
b、如果调用的函数栈很深，一层层返回错误码，处理很难受
c、拿到错误码，需要查找错误码表，才知道是什么错误
*/

//面对上面的问题，C++通过异常来解决

//int main()
//{
//	vector<int> vec = { 1,2,3,4,5 };
//	try 
//	{
//		for (int i = 0; i <= vec.size(); ++i)
//		{
//			//cout << vec[i] << "  ";//[]是通过assert断言(强势)，控制下标不能越界
//			cout << vec.at(i) << "  ";//at是通过抛异常
//		}
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

/*
int Div(int x, int y)
{
	if (y == 0)
	{
		//throw "fasf";  //未知类型

		throw string("发生除零错误");//throw可以抛出任意类型的对象
		//直接跳转到catch匹配的地方，类型相匹配;是调用链中与该对象类型匹配且离抛出异常位置最近的那一个
		//匹配的是调用栈中最近的catch，如果main中也没有匹配的catch，则程序终止

	}
	return x / y;
}

void f1(int x, int y)
{
	try {
		Div(x, y);
	}
	catch(const string& err)//是调用链中与该对象类型匹配且离抛出异常位置最近的那一个
	{
		cout << __LINE__<<err << endl;
	}
}
int main()
{
	try
	{
		int x = 3;
		int y = 0;
		f1(x, y);
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (const string& err)
	{
		cout << __LINE__ << err << endl;
	}
	catch (...)	//捕获没有匹配的任意类型的异常,避免异常没捕获时程序直接终止了
	{
		cout << "未知错误" << endl;
	}
	return 0;
}
*/


//异常的重新抛出

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// 当异常后面出现new或者delete，如果通过throw略过去了delete，就会出现资源泄露问题
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去。
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}


//公司会给一个基类
//要求你可以自己抛自己定义的异常，但是必须继承这个基类
//这样的话，外层捕获就只需要捕获基类就可以；通过这种方式可以让不同的组之间发现是哪一组出现了问题
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg)
//		, _id(id)
//	{
//	}
//	virtual string what() const
//	{
//		return _errmsg; 
//	}
//protected:
//	string _errmsg;//错误描述
//	int _id;//错误码
//	//stack<string> _st;//调用栈帧
//};
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg,const int& id):Exception(errmsg,id)
//	{ }
//	string what()
//	{
//		return "数据库错误" + _errmsg;
//	}
//};
//class NetException : public Exception
//{
//public:
//	NetException(const string& errmsg, const int& id) :Exception(errmsg, id)
//	{
//	}
//	string what()
//	{
//		return "网络错误" + _errmsg;
//	}
//};
//void ServerStart()
//{
//	//模拟出现问题的抛异常
//	if (rand() % 11 == 0)
//	{
//		throw SqlException("数据库启动失败",1);//抛出子类，用父类去catch
//	}
//	if (rand() % 3 == 0)
//	{
//		throw NetException("网络启动失败", 2);//抛出子类，用父类去catch
//	}
//	cout << "正常运行" << endl;
//}
//int main()
//{
//	for (int i = 0; i < 100; ++i)
//	{
//		try { 
//			ServerStart();
//		}
//		catch (Exception& e)//抛出子类，用父类去catch捕获。
//		{
//			 //继承+多态，谁传的，就调用谁的what()
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "未知错误" << endl;
//		}
//	}
//	return 0;
//}


//异常可能会导致异常安全问题
//new /fopen /lock
//func(); // 如果抛异常就会有异常安全问题 ->捕获重新抛出 or RAII 解决
//delete/fclose/ unlock

//函数规范：如果要抛异常，你说明清楚，不抛异常也说明一下
/*
//这里表示这个函数会抛出A / B / C / D中的某种类型的异常
void fun() throw (A,B,C.D):

//这里表示这个函数只会抛出bad_alloc的异常
void* operator new(std::size_t size) throw (std::bad_alloc);

//这里表示这个函数不会抛出异常throw()与noexcept; C++11 中新增的noexcept，表示不会抛异常
void* operator delete(std::size_t size, void* ptr) throw();
void* operatorrdelete(std::size_t size, void* ptr) noexcept;
*/
//异常安全:
//	构造函数完成对象的构造和初始化，最好不要在构造函数中抛出异常，否则可能导致对象不完整或没有完全初始化
//	析构函数主要完成资源的清理，最好不要在析构函数内抛出异常，否则可能导致资源泄漏(内存泄漏、句柄未关闭等)
//C++中异常经常会导致资源泄漏的问题，比如在new和delete中抛出了异常，导致内存泄漏，在lock和unlock之间抛出了异常导致死锁，C++经常使用RAII来解决以上问题，关于RAII是智能指针方面的。


/*
异常总结：

优点:
1、清晰的包含错误信息
2、面对T operator[](int i)这样函数越界错误，异常可以很好的解决
3、多层调用时，里面发生错误，不再需要层层处理，最外层直接捕获即可
4、很多第三方库都是用异常，我们也使用异常可以更好的使用他们。比如:boost、gtest、gmock

缺点:
1、异常会导致执行流乱跳。会给我调试分析程序bug带来一些困难。
2、C++没有GC(垃圾回收机制)，异常可能到导致资源泄露等异常安全问题。 需要学会使用RAII来解决。
3、C++的库里面的异常体系定义不太好用，很多公司都会选择自己定义。
4、C++的异常语言可以抛任意类型的异常，如果项目中没有做很好规范管理，那么会非常的混乱，所以一般需要定义出继承体系的异常规范。
5、异常会有一些性能的开销。当然在现代硬件速度很快的情况下，这个影响基本忽略不计。

异常整体而言还是一个利大于弊的东西，所以实际日常练习或者小项目，不太使用.公司一般还是会选择异常来处理错误
*/

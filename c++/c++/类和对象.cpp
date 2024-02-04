// #include <iostream>
// #include<cstdlib>
// using namespace std;

//类的六个默认成员函数：
//构造函数、拷贝构造函数、析构函数、赋值运算符重载、取地址运算符重载、const修饰的取地址运算符重载

//对象调用const成员函数

//class Date
//{
//public:
//	Date(int year=0, int month=1, int day=1)
// //全省函数也是默认构造函数
// //函数参数默认值（缺省函数）指定默认值的参数必须位于形参列表最右端，从右往左。
// //缺省参数不能在函数声明和定义中同时出现,一般只在声明中出现
// //缺省值必须是常量或者全局变量，但一般不使用全局变量，存在线程安全问题
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//void print()  //void print(Date* this)
//	//{
//	//	cout << this->_year << endl;
//	//}
//
//
//	void print() const  //void print(const Date* this)  不能直接在()里面写  const 修饰的是this指针所指向的对象，则不能再修改对象的内容
//	{
//		cout << this->_year << endl;
//		//_year = 1;//不能修改对象的成员变量
//	}
//private:
//	int _month;
//	int _year;
//	int _day;
//};
////
////void fun(Date& d)
////{
////	d.print();
////}
//
////Date& d前面加上const，再调用d.print();
////实际上是d.print(&d); &d是const Date* ,成员函数传参默认是Date* this,void print(Date* this),属于权限的放大，需要在成员函数后面加上const
//
//void fun(const Date& d)
//{
//	d.print();
//}
//int main()
//{
//	Date d1(12, 21, 2);
//	fun(d1);
//	d1.print();//Date* 传给const Date* ,权限缩小，可以
//	return 0;
//}



//成员函数调用const成员函数

//class Date
//{
//public:
//	Date(int year=0, int month=1, int day=1) 
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//f1调用f2属于权限缩小
//	void f1()		//void f1(Date* this)
//	{
//		f2();		//this->f2(this)
//	}
//	void f2()const	//void f2(const Date* this)
//	{}
//
//
//	//f4调用f3是权限放大，出错
//	void f3()		//void f3(Date* this)
//	{}
//	void f4()const	//void f4(cosnt Date* this)
//	{
//		f3();		//this->f3(this)
//	}
//private:
//	int _month;
//	int _year;
//	int _day;
//};
//
//int main()
//{
//	Date d1(12, 21, 2);
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//取地址运算符重载
//	Date* operator&()
//	{
//		cout << "非const取地址运算符重载" << endl;
//		return this;
//	}
//
//	//	const取地址运算符重载
//	const Date* operator&()const
//	{
//		cout << "const取地址运算符重载" << endl;
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(1, 1, 1);
//	Date d2(2024, 2, 2);
//	cout << &d1 << endl;
//		cout<< &d2 << endl;
//	const Date d3(2, 2, 2);
//	cout << &d3 << endl;
//	return 0;
//}  



//内联函数最初的目的：代替部分 #define 宏定义；
////使用内联函数替代普通函数的目的：提高程序的运行效率；
//C++中在类内定义的所有函数都自动称为内联函数（隐式内联）
//内联函数本身也是一个真正的函数，具有普通函数的所有行为，唯一不同之处在于内联函数会在适当地方像预定义宏一样展开，
//在程序运行时不再进行函数调用和返回，从而消除函数调用和返回的系统开销, 提高了程序执行效率。


//什么时候成员函数加上const修饰
//只要成员函数中不直接或间接修改成员变量最好都要加上const
//因为加上const之后不管是const对象还是非const对象都可以调用



//初始化列表
//const成员变量、引用、自定义类型成员(没有默认构造函数)  
//这三种必须在初始化列表内初始化，因为这三种必须在定义的时候进行初始化
//可以把初始化列表理解为成员变量定义的地方
//尽量使用初始化列表去初始化，因为不管你是否使用初始化列表，对于自定义类型的成员变量，一定会先使用初始化列表初始化
//class A
//{
//public:
//	A(int a,int ref):_b(a),_i(ref),_n(10)
//	{
//		//成员变量的定义
//	}
//private:
//	//成员变量的声明
//	B _b;
//	int& _i;
//	const int _n;
//};
//class B
//{
//public:
//	B(int a) :_a(a)
//	{
//
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int i)
//	{
//		_i = i;
//	}
//private:
//	int _i;
//	Time _time;
//};
//class Time
//{
//public:
//	Time(int hour=0):_hour(hour)
//	{}
//private:
//	int _hour;
//};
//int main()
//{
//	Date d(1);
//	return 0;
//}
//尽量使用初始化列表去初始化，因为不管你是否使用初始化列表，对于自定义类型的成员变量，一定会先使用初始化列表初始化

//成员变量声明的次序才是初始化列表的初始化顺序，与其在初始化列表的先后次序无关
//class A
//{
//public:
//	A(int a):_a1(a),_a2(_a1)
//	{}
//	void print()
//	{
//		cout << _a1 << endl << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//	//先声明a2,其次a1，则在初始化列表里也是先初始化a2，其次是a1
//	
//};
//int main()
//{
//	A test(1);
//	test.print(); 
//	//_a1是1，而_a2是随机值
//	//成员变量声明的次序才是初始化列表的初始化顺序，与其在初始化列表的先后次序无关
//	return 0;
//}
//


//explicit  防止构造函数进行隐式类型转换

//C++98
//class Date
//{
//public:
//	explicit Date(int year):_year(year)
//	{
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(1);//直接构造
//	Date d2 = 2;//隐式类型的转换 构造出tmp(2),再用tmp拷贝构造d2(tmp),然后编译器优化成直接构造
//	const Date& d3 = 3; // 引用就是中间产生的临时对象
//
//	Date d4 = d2;//拷贝构造
//
//	int i = 2;
//	const double& d = i;//隐式类型转换，会产生中间的临时变量(具有常属性）
//
//	return 0;
//}

//C++11  多个参数
//class Date
//{
//public:
//	explicit Date(int year,int month,int day) :_year(year)
//	{
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(1, 2, 3);//直接构造
//	Date d2 = { 2,3,4 };//隐式类型转化，使用花括号，C++11才支持
//	return 0;
//}



//static静态成员
//静态成员类内声明，类外定义
//静态成员函数不能访问非静态成员
//class A
//{
//public:
//	A(int a):_a(a)
//	{
//		++n;
//	}
//	void f()
//	{
//		++n;
//		getn();//非静态成员函数可以调用静态成员函数
//	}
//	static int getn() //静态成员函数没有this指针，不使用对象就可以调用，不能访问非静态成员(成员函数和成员变量)
//	{
//		//_a = 1; //不能访问非静态成员(成员函数和成员变量)
//		return n;
//	}
//private:
//	int _a;
//	
//	static int n;//类内声明，静态成员不属于某个对象，属于类的所有对象，属于这个类
//	//n不在对象中，在静态区
//};
//int A::n = 0;  //类外定义
//int main()
//{
//	A aa(1);
//	aa.f();
//	A aa2(2);
//	aa2.f();
//	//cout << a::n << endl;
//	cout << A::getn() << endl;//调用静态成员函数
//	return 0;
//}

//class Sum {
//public:
//	Sum()
//	{
//		_sum += _n;
//		++_n;
//	}
//	static int GetSum()
//	{
//		return _sum;
//	}
//	static void Init()
//	{
//		_sum = 0;
//		_n = 1;
//	}
//private:
//	static int _n;
//	static int _sum;
//};
//int Sum::_n = 1;
//int Sum::_sum = 0;
//int main()
//{
//	Sum a[10]; //数组，每一个都调用一次构造函数
//	cout << "1+2+...+10=" << Sum::GetSum() << endl;
//	Sum::Init();
//	Sum b[20];
//	cout << "1+2+...+20=" << Sum::GetSum() << endl;
//	return 0;
//}

//
//class A
//{
//public:
//	//给了缺省值就用这个值，否则使用声明的缺省值
//	A():_year(10)
//	{}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//C++11支持
//	//非静态成员变量，声明的时候可以给缺省值
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//int main()
//{
//	A a;
//	a.print();
//	return 0;
//}



//友元

//友元函数可以访问类内的私有成员和保护成员，但不是类的成员函数
// 友元函数不能用const修饰
// 友元函数可以在类定义的任何地方声明，不受访问限定符限制
// 
//class A
//{
//
//	//friend void operator<<(ostream& cout, const A& a);//友元函数可以访问类内的私有成员
//	friend ostream& operator<<(ostream& cout, const A& a);
//	//friend void operator>>(istream& cin, A& a);
//	friend istream& operator>>(istream& cin, A& a);
//public:
//	A(int year=0,int month=1,int day=1):_year(year),_month(month),_day(day)
//	{}
//	void operator<<(ostream& cout)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year ;
//	int _month ;
//	int _day ;
//};
////
////void operator<<(ostream& cout,const A& a)
////{
////	cout << a._year << "-" << a._month << "-" << a._day << endl;
////}
//
////链式操作
//ostream&  operator<<(ostream& cout, const A& a)
//{
//	cout << a._year << "-" << a._month << "-" << a._day << endl;
//	return cout;
//}
//
////void operator>>(istream& cin, A& a)
////{
////	cin >> a._year >> a._month >> a._day;
////}
//
////链式操作输入
//istream&  operator>>(istream& cin, A& a)
//{
//	cin >> a._year >> a._month >> a._day;
//	return cin;
//}
//int main()
//{
//	A a;
//	//cout << a;
//	//使用成员函数重载运算符，因为this指针占第一位，是双目运算符左边的值，
//	// 会造成cout的顺序颠倒，可读性差,所以不能使用成员函数重载<<运算符
//	a << cout;
//
//	cout << a;//但不能链式操作
//	
//	A a2(2, 2, 2);
//	cout << a << a2 << a << a2 << endl;
//
//	cin >> a2>>a;
//	cout << a2<<a;
//	return 0;
//}


//友元类

//class Time
//{
//	friend class Date;//友元类可以访问当前类的私有成员和保护成员
//public:
//	Time() :_hour(10)
//	{}
//private:
//	int _hour;
//};
//class Date
//{
//
//public:
//	void GetTime()
//	{
//		cout << _t._hour;
//	}
//private:
//	int _a;
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	d.GetTime();
//	return 0;
//}


//内部类

// class A
// {
// public:
// 	A():_a(20)
// 	{}
// 	class B  //内部类天生就是A的友元类，可以访问A的私有成员和保护成员
// 	{
// 	public:
// 		void fun(const A& a)
// 		{
// 			cout << a.k << endl;
// 			cout << k << endl;
// 			cout << a._a << endl;
// 		}
// 	};
// private:
// 	int _a;
// 	static int k;
// };
// int A::k = 0;
// int main()
// {
// 	A a;
// 	A::B b;  //定义内部类对象
// 	b.fun(a);
// 	return 0;
// }



//匿名对象
//
//class MyClass
//{
//public:
//	MyClass()
//	{
//		cout << "MyClass" << endl;
//	}
//	~MyClass()
//	{
//		cout << "~MyClass" << endl;
//	}
//	void test()
//	{
//		cout << "test" << endl;
//	}
//
//private:
//
//};
//int main()
//{
//	MyClass m1;  //m1的生命周期在整个main函数
//	m1.test();
//	
//	//MyClass()  匿名对象  生命周期只在这一行
//	MyClass().test();  //只有这一行会使用到这个创建对象，别人不再使用
//	return 0;
//}

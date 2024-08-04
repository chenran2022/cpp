#include<iostream>
using namespace std;

//类型模板参数
//template<class T>
//template<typename T>
//class A
//{};


//类型模板参数 + 非类型模板参数
//template<class T, int N>
//class Array
//{
//public:
//	Array()
//	{
//		//N = 10; //非类型模板参数不可修改
//	}
//private:
//	T _a[N];
//};
//
////double/string 都不可以作为非类型模板参数
////long long/long/int/short/char可以作为非类型模板参数,都属于整型家族
////template<class T, double N>
////template<class T, string N>
///*
//1.浮点数、类对象以及字符串是不允许作为非类型模板参数的,
//2.非类型的模板参数必须在编译期就能确认结果。非类型的模板参数不可以修改，是个常量
//*/
//int main()
//{
//	Array<int, 10> a1;
//	Array<int, 100> a2;
//	return 0;
//}


//模板的特化

template<class T>
bool IsEqual(T& a, T& b)
{
	//当类型是指针的时候，判断字符串相等就不能使用这种方式
	return a == b;
}

//函数的特化 对某些类型的特殊处理
template<>
bool IsEqual<char*>(char*& a, char*& b)
{
	
	return strcmp(a,b) == 0;
}

template<class T1,class T2>
class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
private:
	T1 _a;
	T2 _b;
};

//类的特化
//特化分为全特化和偏特化

//全特化：全部的参数都特化
template<>
class Person<int*,int>
{
public:
	Person()
	{
		cout << "全特化Person<int*,int>" << endl;
	}
private:
	int* _a;
	int _b;
};


//偏特化：只有部分参数特化/或者对参数进一步限制
template<class T2>//只有部分参数特化
class Person<int*, T2>
{
public:
	Person()
	{
		cout << "（偏特化）Person<int*,T2>" << endl;
	}
private:
	T2 _a;
	int* _b;
};

template<class T1, class T2>//对参数进一步限制
class Person<T1*,T2*> //参数必须是两个指针才能匹配，注意:在初始化变量时两种偏特化方式不能同时匹配
{
public:
	Person()
	{
		cout << "偏特化Person<T1*,T2*>" << endl;
	}
private:
	T1 _a;
	T2 _b;
};

template<class T1, class T2>//对参数进一步限制
class Person<T1&, T2&> //参数必须是两个引用才能匹配，注意:在初始化变量时两种偏特化方式不能同时匹配
{
public:
	Person()
	{
		cout << "偏特化Person<T1&, T2&>" << endl;
	}
private:
	T1 _a;
	T2 _b;
};
//int main()
//{
//	int a = 1;
//	int b = 10;
//	cout << IsEqual(a, b) << endl;
//	char* c1 = "abcd";
//	char* c2 = "edfa";
//	cout << IsEqual(c1, c2) << endl;
//
//	Person<int,int> p1;
//	Person<int*,int> p2;//全特化
//	Person<int*, double> p3;//偏特化
//	Person<char*, char*> p4;//偏特化
//	Person<char&, char&> p5;//偏特化
//	//注意:在初始化变量时两种偏特化方式不能同时匹配
//	return 0;
//}


/*
分离编译
项目工程中一般将函数或者类的声明放到.h，将函数或者类的定义放到.cpp
为什么要分离编译呢? 方便查看和维护。
一个程序（项目）由若干个源文件共同实现，而每个源文件单独编译生成目标文件，
最后将所有目标文件链接起来形成单一的可执行文件的过程称为分离编译模式。
*/
//普通的类和函数都要进行分离编译，而模板不能进行分离编译，是由于实例化导致的
//下面代码里的Func1就是实例化导致链接错误，符号表里没有Func1,链接不到，链接错误
//解决模板不能分离编译的方法:
//1、模板定义的位置显式实例化。显示实例化 不常用，因为不方便（Func2、Func3)
//2、粗暴，就是不要分离编译了。将声明和定义放到一个文件 "xxx.hpp" 里面或者xxx.h其实也是可以的。推荐使用这种。（Func4)

//ps:以下声明是放在.h文件里的代码(为了方便以后查看复习)
template<class T>
void Func1(const T& x);

template<class T>
void Func2(const T& x);

template<class T>
void Func3(const T& x);

template<class T>
void Func4(const T& x);

template<class T>
void Func4(const T& x)
{
	cout << "void Func4(const T& x)" << endl;
}
//ps:以下定义是放在.cpp文件里的代码(为了方便以后查看复习)
template<class T>
void Func1(const T& x)
{
	cout << "void Func1(const T& x)" << endl;
}

template<class T>
void Func2(const T& x)
{
	cout << "void Func2(const T& x)" << endl;
}

template<class T>
void Func3(const T& x)
{
	cout << "void Func3(const T& x)" << endl;
}
//显式实例化,只能实例化出一种，多种要实例化出多种
template
void Func2<int>(const int& x);

template
void Func3<double>(const double& x);


//ps:以下main是放在源文件里的代码(为了方便以后查看复习)
int main()
{
	Func1(1);//应该报错，但在这里没报错是因为声明和定义都在cpp里，就是解决方法的第二种
	Func2(2);
	Func3(10.1);
	Func4(1);
	Func4('a');
	Func4("fdasf");
	return 0;
}

/*
模板总结
【优点】
1. 模板复用了代码，节省资源，更快的迭代开发，C++的标准模板库(STL)因此而产生
2. 增强了代码的灵活性
【缺陷】
1. 模板会导致代码膨胀问题，也会导致编译时间变长
2. 出现模板编译错误时，错误信息非常凌乱，不易定位错误
*/

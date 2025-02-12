#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>

#include<initializer_list>
using namespace std;


//C++11统一的列表初始化
//
//class Point
//{
//public:
//	Point(int x,int y):_x(x),_y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//int main()
//{
//	//｛｝初始化
//	int x = 1;
//	int y{ 2 };
//
//	vector<int> v1{ 1,2,3 };
//	vector<int> v2 = { 1,2,3 };
//
//	list<int> l1{ 1,2,3 };
//	list<int> l2 = { 1,2,3 };
//
//	map<string, int> m1{ {"string",1},{"char",2},{"int",3}};
//	map<string, int> m2 = { {"string",1},{"char",2},{"int",3}};
//
//	//这三种方式等价，都是调用Point的构造函数
//	Point p(1, 2);
//	Point p1{ 1, 2 };
//	Point p2 = { 1, 2 };
//
//	//C++11是通过一个容器实现列表初始化 std::initializer_list
//	auto ilt_1 = { 1,2,3 };
//	initializer_list<int> ilt_2 = { 1,2,3 };
//
//	//容器支持花括号列表初始化，本质是增加一个initializer_list的构造函数
//	//initializer_list可以接收{}列表
//	/*
//	vector(initializer_list<T> l)
//	{
//		_start = new T[l.size()]; //vector开空间
//		_finish = _start + l.size();
//		_endofstorage = _start + l.size();
//		iterator vit = _start;
//		typename initializer_list<T>::iterator lit = l.begin();
//		while (lit != l.end())
//		{
//			*vit++ = *lit++; //进行遍历，一个个放进vector内
//		}
//	}
//	//其他容器也类似
//	*/
//	return 0;
//}


/*
类型推导，属于RTTI : run time type Identification
程序运行起来对对象的类型识别
*/
//int main()
//{
//	int a = 10;
//	double b = 20;
//
//	auto c = a + b;//类型转换，向上转化
//
//	//拿到类型名称的字符串
//	cout << typeid(c).name() << endl;
//
//	string s;
//	cout << typeid(s).name() << endl;
//
//	//如果想定义一个跟c和s类型一样的对象
//	//decltype 可以根据对象去推类型
//	decltype(c) c_type;
//	decltype(s) s_type;
//	cout << typeid(c_type).name() << endl;
//	cout << typeid(s_type).name() << endl;
//
//	return 0;
//}


//auto 和 范围for  ->简化代码的写法
/*
auto 不可以作为形参和返回值，可以作为实参传递函数
auto Func(auto au)
{}
*/
//int main()
//{
//	std::map<std::string, int> m2 = { {"string",1},{"char",2},{"int",3}};
//	std::map<std::string, int>::iterator it1 = m2.begin();
//	auto it2 = m2.begin();
//	/*
//	这里it1和it2可以认为是完全一个类型的对象
//	唯一差别是it2的类型是编译器自动推导出来
//	auto的优势就是可以把在类型比较复杂地方，简化代码的写法
//	*/
//	
//	//这里要注意当容器存对象比较大，或者这个对象要做深拷贝，如string
//	//最好给& 和const、可以减少拷贝提高效率
//	//容器支持范围for原理:范围for会被编译器替换成迭代器，也就是意味着支持迭代器就支持范围for
//	//for (auto e : m2)尽量要带上const &
//	for(const auto& e : m2)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//	for (const std::pair<const std::string, int>& e : m2)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//
//	//除了STL的容器可以使用范围for用法，数组也可
//	int arr[] = { 1,2,3,4 };
//	for (const auto& e : arr)
//	{
//		cout << e << " " ;
//	}
//	return 0;
//}

/*
final与override(了解)
回忆一下这两个关键字分别的作用是什么?
fina1修饰类，类就变成了最终类，不能被继承
fina1还可以修饰虚函数，这个虚函数不能被重写
override是子类重写虚函数，检查是否完成重写。不满足重写的条件，则报错
*/


/*
新容器

C++98容器
string/vector/list/deque/map/set/bitset + stack/queue/priority_queue

C++11新容器
array(定长数组):实际中用的很少，缺点:定长 + 存储数据的空间在栈上,栈的空间本来就不大。
forword list(单链表):实际中用得少，缺点:不支持尾插尾删 + insert插入数据也是在当前位置的后面
unordered_map/unordered_set :推荐使用，因为他们的效率高于map/set
*/

//默认成员函数控制

//class A
//{
//public:
//	A(const int& a):_a(a)
//	{ }
//private:
//	int _a;
//};
//int main()
//{
//	//A a1;//默认构造不能使用，因为写了拷贝构造，就不会自动生成默认构造了
//	A  a2(11);
//	return 0;
//}


//class A
//{
//public:
//	A(const int& a) :_a(a)
//	{
//	}
//
//	A() = default; //指定显示去生成默认构造函数，使用缺省值
//private:
//	int _a=10;
//};
//int main()
//{
//	A a1;
//	A  a2(11);
//	return 0;
//}

//要求A的对象不能进行拷贝赋值（防拷贝）
//class A
//{
//public:
//	A() = default; //指定显示去生成默认构造函数，使用缺省值
//
//	//C++98的做法：
//	//只声明，不实现，这样就没办法拷贝构造。缺陷：可以在类外面进行定义实现
//	//为了解决这个缺陷，把声明放在private里,
//private:
//	A(const A& a);
//	
//private:
//	int _a = 10;
//};
////在类外面进行定义实现
//A::A(const A& a):_a(a._a)
//{ }
//int main()
//{
//	A a1;
//	A  a2(a1);
//
//	return 0;
//}



//要求A的对象不能进行拷贝赋值（防拷贝）
//class A
//{
//public:
//	A() = default; //指定显示去生成默认构造函数，使用缺省值
//
//	//C++11的做法：使用delete不让生成
//	A(const A& a) = delete;
//	A& operator=(const A& a) = delete;
//private:
//	int _a = 10;
//};
//int main()
//{
//	A a1;
//	A  a2(a1);
//	return 0;
//}


//右值引用和移动语义(重点)
//C++98就提出了引用的概念，引用就给一个对象取别名
//C++98 左值引用
//C++11 右值引用
//不管是左值引用，还是右值引用，他们都是给对象取别名，
// 从概念上来说，取别名是不开空间的，是给已有的对象空间起了一个新名称
//不过左值引用主要是给左值取别名，右值引用主要是给右值取别名
//
//什么是左值 ? 什么是右值 ?
//	= 左边就是左值 ? 右边的就是右值 ? 注意这个是一个C语法就留下的坑，就像左移和右移一样，
//	这里左右不是方向。左边的值也不一定左值，右边的值不一定是右值
//	int xl = 10 , int x2 = xl  ,这里x1是左值，10是右值，x2是左值
//	可以修改就可以认为是左值，左值通常是变量
//	右值通常是常量、表达式或者函数返回值等 临时对象

//int main()
//{
//	//	可以修改就可以认为是左值，左值通常是变量
//	//	右值通常是常量、表达式或者函数返回值等 临时对象
//
//	//左值引用的定义
//	int a = 1;
//	int& b = a;
//
//	//左值引用不可以引用右值，但是const左值可以引用右值
//	/*int& c = 1;
//	int& d= a + 1;*/
//	const int& c = 1;
//	const int& d = a + 1;//表达式a + 1值也是右值
//
//	//右值引用的定义
//	int x = 1, y = 2;
//	int&& aa = 1;
//	int&& bb = x + y;
//
//	//右值引用不可以引用左值，但是可以引用move后右值
//	//int&& cc = x;
//	int&& dd = move(x);
//	return 0;
//}


//template<class T>
//void func(const T& t)
//{
//	cout << "void func(const T& t)" << endl;
//}
//
//template<class T>
//void func(const T&& t)
//{
//	cout << "void func(const T&& t)" << endl;
//}
//int main()
//{
//	int x = 1;
//	func(x);//左值引用
//	func(1);//右值引用
//	func(x + 1);//右值引用
//	return 0;
//}

//C++11又将右值区分为:纯右值和将亡值
//纯右值 : 基本类型的常量或者临时对象
//将亡值 : 自定义类型的临时对象

class String
{
public:
	String(const char* str="")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)//const左值可以引用右值，但是深拷贝消耗代价太大
	{
		cout << "String(const String& s) --深拷贝-效率低" << endl;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	//右值-将亡值，没必要进行深拷贝,进行移动拷贝，效率高
	String(String&& s):_str(nullptr)
	{
		cout << "String(const String& s) --移动拷贝-效率高" << endl;
		swap(_str, s._str);
	}

	~String()
	{
		delete[] _str; 
	}
private:
	char* _str;
};
String fun(const char* str)
{
	String tmp(str);
	return tmp;//这里返回的实际上是tmp拷贝的临时对象，属于右值
}
int main()
{
	String s1("hello");
	String s2(s1);//参数是左值

	//String s3(String("临时对象"));//参数是右值，匿名对象也是临时对象.但是这里编译器会优化掉
	String s4(fun("临时对象"));//参数是右值-函数返回值，这里是自定义类型的临时对象，也就是将亡值(传递给你用，用完就析构)


	return 0;
}

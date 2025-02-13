#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include <algorithm>
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

//const T& 既可以引用左值，也可以引用右值；
//当没有const T&& 函数重载时，右值传入const T&；当有const T&& 函数重载时，右值传入const T&&
// 
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
//结论:所有深拷贝类(vector/list/map/set.都可以加两个右值引用做参数的移动拷贝和移动赋值
//现实中不可避免存在传值返回的场景，传值返回的拷贝返回对象的临时对象。
//如果只有深拷贝，那么代码就很大，实现右值引用的移动拷贝，效率高
//结论:右值引用本身没太多意义，右值引用的实现了移动构造和移动赋值
//那么面对接收函数传值返回对象(右值)等等场景，可以提高效率
//class String
//{
//public:
//	String(const char* str="")
//	{
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	String(const String& s)//const左值可以引用右值，但是深拷贝消耗代价太大
//	{
//		cout << "String(const String& s) --深拷贝-效率低" << endl;
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//
//	//右值-将亡值，没必要进行深拷贝,进行移动拷贝，效率高
//	String(String&& s):_str(nullptr)
//	{
//		cout << "String(const String&& s) --移动拷贝-效率高" << endl;
//		swap(_str, s._str);
//	}
//
//	//string = 左值
//	String& operator=(const String& s)
//	{
//		cout << "String& operator=(const String& s) --深拷贝赋值-效率低" << endl;
//
//		if (this != &s)
//		{
//			char* newstr = new char[strlen(s._str) + 1];
//			strcpy(newstr, s._str);
//
//			if (_str)
//			{
//				delete[] _str;
//			}
//			_str = newstr;
//		}
//		return *this;
//	}
//
//	//string = 右值，将亡值
//	String& operator=(String&& s)
//	{
//		swap(_str, s._str);
//		cout << "String& operator=(String&& s) --移动赋值-效率高" << endl;
//		return *this;
//	}
//
//	//s1 + s2
//	String operator+(const String& s)
//	{
//		String ret(*this);
//		//ret.append(s);
//		return ret;//传值返回的拷贝返回对象的临时对象。返回的是右值。
//	}
//
//	//s1 += s2
//	String& operator+=(const String& s)
//	{
//		//this->append(s);
//		return *this;//返回的是左值
//	}
//	~String()
//	{
//		delete[] _str; 
//	}
//private:
//	char* _str;
//};
//String fun(const char* str)
//{
//	String tmp(str);
//	return tmp;//这里返回的实际上是tmp拷贝的临时对象，属于右值
//}
//int main()
//{
//	String s1("hello");
//	String s2(s1);//参数是左值
//
//	//String s3(String("临时对象"));//参数是右值，匿名对象也是临时对象.但是这里编译器会优化掉
//	String s4(fun("临时对象"));//参数是右值-函数返回值，这里是自定义类型的临时对象，也就是将亡值(传递给你用，用完就析构)
//
//	String s5(move(s1));
//	//move(s1)后，s1变成了空
//	//当需要用右值引用引用一个左值时，可以通过move函数将左值转化为右值。
//	//C++11中，std::move()函数位于头文件<utility>中，该函数名字具有迷惑性，
//	//它并不搬移任何东西，唯一的功能就是将一个左值强制转化为右值引用，然后实现移动语义
//	cout << endl;
//
//	String s6;
//	s6 = s5;
//	s6 = move(s2);
//	cout << endl;
//
//	String s7 = s5 + s4;  //移动构造
//	String s8 = s7 += s4; //拷贝构造
//	return 0;
//}


//右值引用去做函数的参数
/*
std::vector::push_back
void push_back(const value _type& val);
void push_back(value_type&& val);

std::list::push_back
void push_back(const value_type& val);
void push_back(value_type&& val);

std::set::insert
pair<iterator, bool>insert(const value_type& val);
pair<iterator, bool>insert(value_type&& val);

std::vector::emplace back
template<class... Args>
void emplace_back(Args&&... args); // template<class... Args>是模板的可变参数 (了解),可以是一个或多个参数
网上有人说:emplace版本表push和insert高效。这句话不准确，没有深入去分析。

其他容器的插入数据结构也基本都是两个重载实现，一个左值引用，一个右值引用
*/
//int main()
//{
//	vector<string> vec;
//	int val = 123;
//	string s("左值");
//
//	//调用string的拷贝构造，深拷贝
//	vec.push_back(s);//void push_back(const value _type& val);
//	
//	//调用string的移动构造
//	vec.push_back("右值");//void push_back(value_type&& val);
//	vec.push_back(to_string(val));//void push_back(value_type&& val);
//
//	vec.emplace_back(s);
//	vec.emplace_back("右值");
//	vec.emplace_back(move(s));
//
//	vector<pair<string, int>> vp;
//	vp.push_back(make_pair("右值", 20));
//	//vp.push_back("右值", 20); //push_back不可以传多个参数
//
//	vp.emplace_back(make_pair("右值", 20));
//	vp.emplace_back("右值", 20);//体现emplace_back模板可变参数特点的地方
//	return 0;
//}
/*
总结
右值引用做参数和作返回值减少拷贝的本质是利用了移动构造和移动赋值
左值引用和右值引用本质的作用都是减少拷贝，右值引用本质可以认为是弥补左值引用不足的地方，他们两相辅相成

左值引用:解决的是传参过程中和返回值过程中的拷贝
做参数:void push(T x)->void push(const T& x) 解决的是传参过程中减少拷贝
做返回值:T  f2() -> T&  f2()解决的返回值过程中的拷贝
ps:但是要注意这里有限制，如果返回对象出了作用域不在了就不能用传引用，这个左值引用无法解决，等待C++11右值引用解决

右值引用:解决的是传参后，push/insert函数内部将对象移动到容器空间上的问题 + 传值返回接收返回值的拷贝
做参数: void push(T&&x) 解决的push内部不再使用拷贝构造x到容器空间上，而是移动构造过去
做返回值:T (2): 解决的外面调用接收f20)返回对象的拷贝，T ret = f2(),这里就是右值引用的移动构造，减少了拷贝
*/


//完美转发

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
//// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
//// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
//// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要完美转发
////	std::forward<T>(t) 完美转发在传参的过程中保留对象原生类型属性
//template<typename T>
//void PerfectForward(T&& t)//万能引用
//{
//	//右值引用会在第二次之后的参数传递过程中右值属性丢失,下一层调用会全部识别为左值
//	//完美转发解决
//	//Fun(t);
//	Fun(forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}


//lambda表达式

//
//template<class T>
//struct G1
//{
//	bool operator()(const T& x,const T& y)
//	{
//		return x > y;
//	}
//};
//
//bool g2(const int& x, const int& y)
//{
//	return x > y;
//}
//
//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//
//	G1<int> g1;
//	int a = 10, b = 20;
//	g1(a, b);//g1是一个对象，这里调用的是他的operator()实现的比较,仿函数
//	g2(a, b);//g2是一个函数指针，这里是调用他指向的函数
//	//他们是完全不同的对象,但是他们用起来是一样的。
//	return 0;
//}

//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price; 			
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
///*
//随着C++语法的发展，人们开始觉得上面的写法太复杂了，每次为了实现一个algorithm算法，
//都要重新去写一个类，如果每次比较的逻辑不一样，还要去实现多个类，特别是相同类的命名，
//这些都给编程者带来了极大的不便。因此，在C++11语法中出现了Lambda表达式。
//*/
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//
//	return 0;
//}

/*
lambda表达式
lambda表达式语法
lambda表达式书写格式：[capture-list] (parameters) mutable -> return-type { statement }

lambda表达式各部分说明
	[capture-list] : 捕捉列表，该列表总是出现在lambda函数的开始位置，
	编译器根据[]来判断接下来的代码是否为lambda函数，捕捉列表能够捕捉上下文中的变量供lambda函数使用。

	(parameters)：参数列表。与普通函数的参数列表一致，如果不需要参数传递，则可以连同()一起省略

	mutable：默认情况下，lambda函数总是一个const函数，
	mutable可以取消其常量性。使用该修饰符时，参数列表不可省略(即使参数为空)。

	->return type：返回值类型。用追踪返回类型形式声明函数的返回值类型，
	没有返回值时此部分可省略。返回值类型明确情况下，也可省略，由编译器对返回类型进行推导。
	
	{statement}：函数体。在该函数体内，除了可以使用其参数外，还可以使用所有捕获到的变量。
注意：
在lambda函数定义中，参数列表和返回值类型都是可选部分，而捕捉列表和函数体可以为空。
因此C++11中最简单的lambda函数为：[]{}; 该lambda函数不能做任何事情。
*/
int main()
{
	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	//没有参数，没有返回值
	[] {};

	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
	int a = 3, b = 4;
	[=] {return a + 3; };

	// 省略了返回值类型，无返回值类型
	auto fun1 = [&](int c) {b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;

	// 各部分都很完善的lambda函数
	auto fun2 = [=, &b](int c)->int {return b += a + c; };
	cout << fun2(10) << endl;

	// 复制捕捉x
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;
	return 0;
}

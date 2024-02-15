#include <iostream>
using namespace std;

//泛型编程：编写与类型无关的代码，代码复用
//模板->写跟类型无关的代码
//模板原理：
//写了模板后，编译器根据调用函数模板和类模板的类型，通过模板实例化出对应的类型的函数或者类，本质上在编译时的的代码量并没有少，只是写的代码少了
//编译器是把模板实例化出对应的类型的函数或者类放到进程中的代码段中去执行，模板并不会被放进代码段


//函数模板
//template<class Tp>
//template<typename T>  //class 和 typename一样，模板参数->类型 ,类型名字随意取，多个参数用逗号隔开
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//template<class t1,class t2>
//void tmp(t1& a,t2& b)
//{
//
//}
//int main()
//{
//	//下面调用的函数并不是同一个函数，调用的是函数模板实例化生成的对应类型的函数，在预处理阶段完成
//	//函数模板并不是函数，只是一个蓝图，是编译器使用方式生产特定具体类型函数的模具，
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << "	" << b << endl;
//	char a1 = 'a';
//	char b1 = 'b';
//	Swap(a1, b1);
//	cout << a1 << "	" <<b1<< endl;
//	return 0;
//}

//template<class T>
//void Swap(T a)
//{
//	int a
//}
//int main()
//{
//	//在没有调用Swap函数模板时，模板内写的内容并不会进行检测，模板不会被实例化出对应的函数，所以错误的内容也能编译成功通过
//	//编译器是把模板实例化出对应的类型的函数或者类放到进程中的代码段中去执行，模板并不会被放进代码段
//
//	//Swap(1);
//	//使用函数模板时，会调用实例化出对应的函数，编译出错
//	return 0;
//}



//类模板

//template<class T>
//class Stack
//{
//public:
//	Stack()
//	{
//
//	}
//	void Push(T x)
//	{
//		
//	}
//	~Stack()
//	{}
//private:
//	T* _a;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	//用C语言实现一个栈有以下几个缺点
//	/*
//	1.忘记初始化和销毁							--》构造函数和析构函数
//	2.没有封装，谁都可以修改结构体的数据		--》类+访问限定符
//	3.如果想同时定义两个栈，一个存int，一个存double，做不到 --》模板
//	*/
//	
//	
//	Stack<int> st_cpp_int;
//	st_cpp_int.Push(1);	//两个参数，有个隐藏的this指针
//	st_cpp_int.Push(1);
//	st_cpp_int.Push(1);
//	st_cpp_int.Push(1);
//	
//	Stack<double> st_cpp_double;
//	st_cpp_double.Push(1.23);
//	return 0;
//}



//类模板的类内声明、类外定义的作用域类型改变
//
//#include<assert.h>
//template<class T>
//class vector	//动态增长的数组
//{
//public:
//	vector():_a(nullptr),_size(0),_capacity(0)
//	{}
//	~vector()
//	{
//		delete(_a);
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	//类内声明
//	void push_back(const T& x);
//	size_t size();
//
//	//一个特殊运算符的重载
//	/*
//	T operator[](size_t i)
//	{
//		assert(i < _size);
//		return _a[i];
//		//返回的是一个临时拷贝对象，临时对象具有常性
//	}
//	*/
//	T& operator[](size_t i)
//	{
//		assert(i < _size);
//		return _a[i];
//	}
//	//引用传参：1、修改传递的实参 比如swap  2、减少拷贝
//	//引用返回传参：1、修改返回对象 比如operator[]  2、减少拷贝
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
////类外定义
////类名字后要加上模板
////vector是类名，vector[int] 才是类型
//template<class T>
//void vector<T>::push_back(const T& x)
//{
//	if (_size == _capacity)
//	{
//		size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
//		T* tmp = new T[newcapacity];
//		if (_a)
//		{
//			memcpy(tmp, _a, sizeof(T) * _size);
//			delete(_a);	
//		}
//		_a = tmp;
//		_capacity = newcapacity;
//	}
//	_a[_size] = x;
//	++_size;
//}
//template<class T>
//size_t vector<T>::size()
//{
//	return _size;
//}
//int main()
//{
//	//vector是类名，vector[int] 才是类型
//	vector<int> vec;
//	vec.push_back(1);
//	vec.push_back(2);
//	vec.push_back(3);
//	vec.push_back(4);
//	
//	int i = 0;
//	for (; i < vec.size(); ++i)
//	{
//		//[]读
//		cout << vec[i] << endl;
//	}
//	
//	i = 0;
//	for (; i < vec.size(); ++i)
//	{
//		//[]写
//		//左值必须是可修改的
//		vec[i] *= 2;
//	}
//	return 0;
//}

//引用传参：1、修改传递的实参 比如swap  2、减少拷贝
//引用返回传参：1、修改返回对象 比如operator[]  2、减少拷贝


//
//template<class T>
//T Add(const T& x,const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a1 = 2, a2 = 1;
//	double b1 = 1.2, b2 = 23.2;
//	//隐式实例化（T的类型是编译器自己推导的）
//	Add(a1, a2);
//	Add(b1, b2);
//
//
//	//Add(a1, b1);//编译错误
//
//	//显示实例化
//	//指定T的类型
//	Add<int>(a1, b1);
//
//
//	return 0;
//}

//
////专门处理int的加法函数
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////通用加法函数
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	Add(1, 2);//优先选择与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 1);//指定选择与模板函数匹配，调用编译器特化的Add函数
//	return 0;
//}

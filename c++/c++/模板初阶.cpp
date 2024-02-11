#include <iostream>
using namespace std;

//泛型编程：编写与类型无关的代码，代码复用
//模板->写跟类型无关的代码
//模板原理：
//写了模板后，调用函数时编译器通过模板实例化出对应的类型的函数或者类，本质上在编译时的的代码量并没有少，只是写的代码少了



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
//	//ps:好像会出错呀！！！
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
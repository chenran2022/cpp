#include<iostream>

using namespace std;

//int main()
//{
//	/*
//	在C语言中，如果赋值运算符左右两侧类型不同，
//	或者形参与实参类型不匹配，或者返回值类型与接收返回值类型不一致时，就需要发生类型转化，
//	C语言中总共有两种形式的类型转换：隐式类型转换和显式类型转换。
//		1. 隐式类型转化：编译器在编译阶段自动进行，能转就转，不能转就编译失败
//		2. 显式类型转化：需要用户自己处理
//	*/
//
//	int i = 1;
//	double d = i;
//	// 隐式类型转换
//	//c语言支持相近类型的隐式类型转换(相近类型，也就是意义相似的类型)
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;	
//	int address = (int)p;// 显式的强制类型转换
//	//c语言支持相近类型的强制类型转换(不相近类型，也就是意义差别很大的类型)
//	printf("%x, %d\n", p, address);
//
//
//	/*
//	C风格的转换格式很简单，但是有不少缺点的：
//		1. 隐式类型转化有些情况下可能会出问题：比如数据精度丢失
//		2. 显式类型转换将所有情况混合在一起，代码不够清晰
//	因此C++提出了自己的类型转化风格，注意因为C++要兼容C语言，所以C++中还可以使用C语言的转化风格。
//
//	标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符：
//	static_cast、reinterpret_cast、const_cast、dynamic_cast
//	*/
//	int i2 = 1;
//	double d2 = 0.2;
//	int* pi = nullptr;
//
//	i2 = static_cast<int>(d);		//对应c语言隐式类型转换(相近类型)，不能用于两个不相关的类型进行转换
//	pi = reinterpret_cast<int*>(i2);//对应c语言大部分强制类型转换(不相近类型)
//
//	const int ci = 20;
//	int* pc = const_cast<int*>(&ci);//对应c语言强制类型转换中去掉const属性的(不相近类型)
//	//int* pc = (int*)&ci;//c语言强制类型转换，同上
//	*pc = 10;
//	cout << *pc << "  " << ci << endl;
//	//结果是10，20
//	//这里打印是10是因为ci存储的内存被改了，但是ci被放进了寄存器，这里去寄存器中取，还是10.
//	//本质这是由于编译器对const对象存取优化机制导致。
//	//想要禁止编译器做这个优化，每次都到内存中去取值，就把volatile加上
//	//volatile 告诉编译器不需要优化volatile声明的变量，让程序可以直接从内存中读取变量。
//	//对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。
//	volatile const int ci2 = 200;//volatile关键字是防止编译器进行优化
//	int* pc2 = const_cast<int*>(&ci2);
//	*pc2 = 100;
//	cout << *pc2 << "  " << ci2 << endl;
//	return 0;
//}

/*
dynamic_cast用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)
向上转型：子类对象指针/引用->父类指针/引用(不需要转换，赋值兼容规则)
向下转型：父类对象指针/引用->子类指针/引用(用dynamic_cast转型是安全的)
注意：
1. dynamic_cast只能用于父类含有虚函数的类
2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0

dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)
因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢?dynamic _cast的原理
dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。
*/
//class A
//{
//	virtual void f()
//	{ }
//public:
//	int _a;
//};
//class B :public A
//{
//public:
//	int _b;
//};
//
//void test(A* pa)
//{
//	//如何区分pa是指向父类，还是子类对象？
//	//B* pb = (B*)pa;//C语言是无法区分的
//
//	B* pb = dynamic_cast<B*>(pa);
//	//如果pa是指向子类对象，则转换成功，如果pa指向父类对象则转换失败返回nullptr
//	if (pb)
//	{
//		pb->_a = 10;
//		pb->_b = 20;
//		cout << "pa是指向子类对象,转换成功" << endl;
//	}
//	else
//	{
//		cout << "pa指向父类对象,转换失败" << endl;
//	}
//	/*
//	dynamic_cast向下转换只能针对继承中的多态类型(父类必须包含虚函数)
//	因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢?dynamic _cast的原理
//	dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。
//	dynamic_cast是通过到pa指向对象的虚表上方找到标识对象的信息
//	如果是父类A，就不让转，返回空
//	如果是子类B，可以转，正常返回对象地址
//	所以要求父类A必须是多态类型
//	*/
//}
//int main()
//{
//	A a;
//	B b;
//	A* pa = &a;
//	test(pa);
//
//	B* pb = &b;
//
//	pa = &b;//C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，这个过程是语法天然支持的，这个叫向上转换。
//	test(pa);
//
//	//pb = &a;//如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程有可能能成功,要看具体情况。
//	//pb = (B*)&a;//强制类型会转换成功，但是会出问题
//	//pb->_b = 10;//造成访问越界
//	return 0;
//}


//explicit关键字，防止隐式转换
class A
{
public:
	explicit A(int a) :_a(a)
	{
		cout << "A(int a)" << endl;
	}
	explicit A(int a,int b) :_a(a),_b(b)
	{
		cout << "A(int a,int b)" << endl;
	}

private:
	int _a;
	int _b;
};
int main()
{
	A a1(1);

	A a = 1;//隐式转换，A tmp(1);  A a = tmp;编译器优化成一次直接构造
	A aa = { 1,2 };//C++11,隐式转换,多个参数使用初始化列表

	/*
	RTTI（了解）
	RTTI：Run-time Type identification的简称，即：运行时类型识别。
	C++通过以下方式来支持RTTI：
		1. typeid运算符
		2. dynamic_cast运算符
		3. decltype
	*/

	return 0;
}

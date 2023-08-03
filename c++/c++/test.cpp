#include<iostream>
using namespace std;


//函数重载
//1:函数在同一定义域
//2:参数的个数不同、类型不同或顺序不同
//3:返回值不可以作为重载的条件

//void test()
//{
//	cout<<"wo"<<endl;
//}
//void test(int a)
//{
//	cout << a << endl;
//}
//
////void test(int a=10, int)//默认参数从左到右必须都是
////{
////	cout << "占位参数" << a<<endl;
////}
//
//void test(int, int b = 10)
//{
//	b = 100;
//	cout << "占位参数" << b << endl;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;//引用，别名.必须初始化，初始化后不能引用其他对象 
//  //int* const b = &a;
//	//b = 20;//*b=20;
//	std::cout << a << b << std::endl; 
//	cout << &a << endl;
//	cout << &b << endl;
//	test(a,b);
//	cout << a << endl;
//	cout << b << endl;
//	system("pause");
//	return 0;
//}


//引用传参：修改目标值

//void test(int& a)
//{
//	a = 100;
//}
//int main()
//{
//
//	int a = 10;
//	test(a);
//	cout << a << endl;
//	system("pause");
//	return 0;
//}


//引用作为函数重载的条件

//void test(int& a)//int &a=10;错误：引用必须指向一块合法的空间，而10是常量
//{
//	cout << "int &a" << endl;
//}
//void test(const int& a)//const int &a，编译器会优化：int tmp=10;const int &a=tmp;tmp占用一块合法的空间，所以会执行成功
//{
//	cout << "const" << endl;
//}
//int main()
//{
//	/*int a = 10;
//	test(a);*/
//
//
//	test(10);
// 
//	system("pause");
//	return 0;
//}

//函数重载参数有默认参数
//
//void test(int a, int b = 10)
//{
//	cout << "int a,int b=10" << endl;
//}
//void test(int a)
//{
//	cout << "int a" << endl;
//}
//
//int main()
//{
//	test(10);//两个函数都可以执行，所以会报错（二义性）
//	system("pause");
//	return 0;
//}

//类和对象
//封装、继承、多态

//#include<string.h>
//
//double PI = 3.14;
//class Circle
//{
//public:
//	double r;
//
//	double Calculate()
//	{
//		return 2 * PI * r;
//	}
//
//};
//
//class Student
//{
//public:
//	string name;
//	string hao;
//
//	void PrintStu()
//	{
//		cout << name << "  " << hao << endl;
//	}
//	void setName(string str)
//	{
//		name = str;
//	}
//};
//int main()
//{
//	Circle a;
//	a.r = 10;
//	cout << a.Calculate() << endl;
//	Student stu;
//	stu.name =  "chenran" ;
//	stu.hao = "202211060901";
//	stu.setName("zhangsan");
//	stu.PrintStu();
//	return 0;
//}

//class 的访问权限
//1：公共权限 public	成员：类内可以访问，类外可以访问
//2：保护权限 protected	成员：类内可以访问	类外不可访问	儿子可以访问父亲中的保护内容
//3：私有权限 private	成员：类内可以访问	类外不可访问	儿子不可访问父亲中的私有内容

//class Person
//{
//public:
//	string name;
//protected:
//	string car;
//private:
//	int password;
//public:
//	void set()
//	{
//		name = "chenran";
//		car = "地板车";
//		password = 54188;
//		cout << name << "  " << car << "  " << password << endl;
//	}//类内可以访问
//};
//int main()
//{
//	Person ps;
//	ps.name = "zhangsan";
//	/*ps.car = "宝马";
//	ps.password = 123456;*/
//	//类外不可访问
//	ps.set();
//	return 0;
//}


//struct与class的区别
//在C++中唯一的区别就是默认权限不同
//struct默认权限是公共权限，class默认权限是私有权限

//class C1
//{
//	int a;
//};
//struct S1
//{
//	int b;
//};
//int main()
//{
//	C1 c;
//	//c.a;//不可访问
//	S1 s;
//	s.b = 10;//可访问
//	system("pause");
//	return 0;
//}


//成员属性设置为私有
//优点1：可以自己控制读写权限
//优点2：对于写权限，可以检测数据的有效性

//#include<string.h>
//class Person
//{
//public:
//	void SetNmae(string str)
//	{
//		name = str;
//	}
//	string GetName()
//	{
//		return name;
//	}
//	void SetAge(int a)
//	{
//		if (a < 0 || a>150)
//		{
//			age = 0;
//			return;
//		}//检测数据的有效性
//		age = a;
//	}
//	
//	string GetLover()
//	{
//		lover = "she";
//		return lover;
//	}
//private:
//	string name;//可读可写
//	int age;//只写
//	string lover;//只读
//};
//int main()
//{
//	Person p;
//	p.SetNmae("chenran");
//	cout << p.GetName() << endl;
//	p.SetAge(19);
//	cout << p.GetLover() << endl;
//	return 0;
//}


//class Cube
//{
//public:
//	void SetCube(int a, int b, int c)
//	{
//		l = a;
//		w = b;
//		h = c;
//	}
//	int GetCubeS()
//	{
//		return 2 * (l * w + l * h + w * h);
//	}
//	int GetCubeV()
//	{
//		return l * w * h;
//	}
//	bool isSame(Cube& c2)
//	{
//		if (GetCubeS() == c2.GetCubeS() && GetCubeV() == c2.GetCubeV())
//			return true;
//		else
//			return false;
//	}
//private:
//	int l;
//	int w;
//	int h;
//};
////bool isSame(Cube& c1, Cube& c2)
////{
////	if (c1.GetCubeS() == c2.GetCubeS() && c1.GetCubeV() == c2.GetCubeV())
////		return true;
////	else
////		return false;
////}
//int main()
//{
//	Cube cube;
//	Cube cube2;
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	cube2.SetCube(a, b, c);
//	cube.SetCube(10, 20, 30);
//	cout << cube.GetCubeS() << endl;
//	cout << cube.GetCubeV() << endl;
//	//int ret=isSame(cube,cube2);
//	int ret = cube.isSame(cube2);
//	if (ret)
//		cout << "相等" << endl;
//	else
//		cout << "不相等" << endl;
//	return 0;
//}

//类的声明与定义

//class Point
//{
//public:
//	void SetPoint(int x, int y)
//	{
//		p_x = x;
//		p_y = y;
//	}
//	int GetPoint_x()
//	{
//		return p_x;
//	}
//	int GetPoint_y()
//	{
//		return	p_y;
//	}
//private:
//	int p_x;
//	int p_y;
//};
//
//class Circle
//{
//public:
//	void SetCircle_r(int r)
//	{
//		m_r = r;
//	}
//	int GetCircle_r()
//	{
//		return m_r;
//	}
//	void SetCenter(Point Center)
//	{
//		m_Center = Center;
//	}
//	Point GetCenter()
//	{
//		return m_Center;
//	}
//private:
//	int m_r;
//	Point m_Center;//圆心
//};

//类的声明与定义
//#include"test.h"
//void Point::SetPoint(int x, int y)
//{
//	p_x = x;
//	p_y = y;
//}
//int Point::GetPoint_x()
//{
//	return p_x;
//}
//int Point::GetPoint_y()
//{
//	return	p_y;
//}
//
//
//void Circle::SetCircle_r(int r)
//{
//	m_r = r;
//}
//int Circle::GetCircle_r()
//{
//	return m_r;
//}
//void Circle::SetCenter(Point Center)
//{
//	m_Center = Center;
//}
//Point Circle::GetCenter()
//{
//	return m_Center;
//}
//void P_C(Point &p,Circle& c)
//{
//	if ((p.GetPoint_x() - c.GetCenter().GetPoint_x()) * (p.GetPoint_x() - c.GetCenter().GetPoint_x())
//		+ (p.GetPoint_y() - c.GetCenter().GetPoint_y()) * (p.GetPoint_y() - c.GetCenter().GetPoint_y())
//		== c.GetCircle_r() * c.GetCircle_r())
//	{
//		cout << "点在圆上"<<endl;
//	}
//	else if ((p.GetPoint_x() - c.GetCenter().GetPoint_x()) * (p.GetPoint_x() - c.GetCenter().GetPoint_x())
//		+ (p.GetPoint_y() - c.GetCenter().GetPoint_y()) * (p.GetPoint_y() - c.GetCenter().GetPoint_y())
//		> c.GetCircle_r() * c.GetCircle_r())
//	{
//		cout << "点在圆外"<<endl;
//	}
//	else
//		cout << "点在圆内"<<endl;
//}
//
//int main()
//{
//	Point p;
//	p.SetPoint(10, 10);
//
//	Point c;
//	c.SetPoint(0, 0);
//
//	Circle C1;
//	C1.SetCenter(c);
//	int r = 10;
//	C1.SetCircle_r(r);
//
//	P_C(p, C1);
//	return 0;
//}


//对象的初始化和清理

//构造函数：创建对象时为对象的成员赋值，构造函数由编译器自动调用，无需手动调用
//析构函数:	对象销毁前系统自动调用，无需手动调用

//class Person
//{
//public:
//	//构造函数：
//		/*	语法：类名(){}
//			没有返回值也不写void
//			函数名称和类名相同
//			构造函数可以有参数，所以可以发生重载
//			程序在调用对象时自动调用构造函数，无需手动调用，且只会调用一次*/
//	Person()
//	{
//		cout << "构造函数" << endl;
//	}
//	//析构函数：
//			/*	语法：~类名(){}
//			没有返回值也不写void
//			函数名称和类名相同，在名称前加上符号~
//			构造函数不可以有参数，所以不可以发生重载
//			程序在对象销毁前自动调用构造函数，无需手动调用，且只会调用一次*/
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//	//注意：构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
//};
//int main()
//{
//
//	Person P;
//	system("pause");
//	return 0;
//}

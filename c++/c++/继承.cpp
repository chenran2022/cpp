#include<iostream>
using namespace std;

/*class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	int _a;
protected:
	string _name = "peter"; // 姓名
private:
	int _age = 18; // 年龄
};
// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。
// 这里体现出了Student和Teacher复用了Person的成员。
// 下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用Print可以看到成员函数的复用。
class Student : public Person
{
public:
	void fun()
	{
		cout << _name << endl;
		//cout << _age << endl;//不可访问
	}
protected:
	int _stuid; // 学号
}; 

//Person是父类，也称作基类。Student是子类，也称作派生类。


class Teacher : public Person
{
protected:
	int _jobid; // 工号
};
int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	
	return 0;
}*/
/*
类成员/继承方式				public继承					protected继承				private继承
基类的public成员		派生类的public成员			派生类的protected成员		派生类的private成员
基类的protected成员		派生类的protected成员		派生类的protected成员		派生类的private成员
基类的private成员		在派生类中不可见			在派生类中不可见			在派生类中不可见

总结：
1.	基类private成员在派生类中无论以什么方式继承都是不可见的。
	这里的不可见是指基类的私有成员还是被继承到了派生类对象中，
	但是语法上限制派生类对象不管在类里面还是类外面都不能去访问它。
2.	基类private成员在派生类中是不能被访问，
	如果基类成员不想在类外直接被访问，但需要在派生类中能访问，就定义为protected。
	可以看出保护成员限定符是因继承才出现的。
3.	实际上面的表格我们进行一下总结会发现，基类的私有成员在子类都是不可见。
	基类的其他成员在子类的访问方式 == Min(成员在基类的访问限定符，继承方式)，public > protected > private。
4.	使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public，不过最好显示的写出继承方式。
5.	在实际运用中一般使用都是public继承，几乎很少使用protetced / private继承，
	也不提倡使用protetced / private继承，
	因为protetced / private继承下来的成员都只能在派生类的类里面使用，实际中扩展维护性不强
*/


/*
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student: public Person
{
public:
	int _No; // 学号
};
int main()
{
	Student sobj;
	//子类与父类之间的复制兼容规则
	// 1.子类对象可以赋值给父类对象/指针/引用
	//这里有个形象的说法叫切片或者切割。寓意把派生类中父类那部分切来赋值过去。
	Person pobj = sobj;
	Person* ptr = &sobj;
	Person& ref = sobj;
	//2.基类对象不能赋值给派生类对象
	sobj = pobj;
	//3.基类的指针可以通过强制类型转换赋值给派生类的指针
	ptr = &sobj;
	Student * ps1 = (Student*)ptr; // 这种情况转换时可以的。
	ps1->_No = 10;
	ptr = &pobj;
	Student* ps2 = (Student*)ptr; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
	return 0;
}
*/



/*
1. 在继承体系中基类和派生类都有独立的作用域,类名就是作用域
2. 子类和父类中有同名成员(包括变量和函数)，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义。（在子类成员函数中，可以使用 基类::基类成员 显示访问）
3. 需要注意的是如果是成员函数的隐藏，只需要函数名相同就构成隐藏。
4. 注意在实际中在继承体系里面最好不要定义同名的成员
*/
/*
class Person
{
protected:
	string _name = "小李子"; // 姓名
	int _num = 111; // 身份证号
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 999; // 学号
};
int main()
{
	Student s;
	s.Print();
	return 0;
}
*/

class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
	//属于隐藏，也叫重定义。不是重载，重载必须是在用一块作用域下
};
int main()
{
	B b;
	//b.fun();//直接调用父类的被重定义的成员函数是不行的，因为被隐藏了
	b.A::fun();
	b.fun(1);
	return 0;
}

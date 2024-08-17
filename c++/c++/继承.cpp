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
	Student* ps1 = (Student*)ptr; // 这种情况转换时可以的。
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

/*
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
}*/


//派生类的默认成员函数

/*
class Person
{
public: 
	Person()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;		
	}
};
class Student :public Person
{

};
int main()
{
	Student stu; 
	//子类继承父类的成员部分是由父类进行初始化构造，清理是由父类析构清理
	return 0;
}
*/

/*
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
			cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;
};
class Student :public Person
{
public:
	//Student(const char* str,const int i) :_name(str),_stuid(i)
	//{
	//}  
	//子类不能直接初始化父类的成员变量，父类的部分必须由父类初始化构造，可以使用Person(str)进行初始化构造，不写的话就调用父类的默认构造函数
	Student(const char* str="wow", const int i=18) :Person(str), _stuid(i)
	{
		cout << "Student(const char* str, const int i)" << endl;
	}

	//Student(const Student& stu) :_name(stu._name), _stuid(stu._stuid)
	//{
	//}
	//拷贝构造，父类的成员部分调用父类的拷贝构造函数
	Student(const Student& stu) :Person(stu), _stuid(stu._stuid)//子类对象赋值给父类，就是切割
	{
		cout << "Student(const Student& stu)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			_stuid = s._stuid;
			//this->operator=(s);
			// 与父类的operator=函数名相同，被隐藏了，不能直接调用
			Person::operator=(s);
		}
		return *this;
	}
	~Student()//子类的析构函数和父类的析构函数构成隐藏，因为他们的名字会被编译器统一处理成destructor（跟多态有关）
	{
		//~Person();//不能直接调用父类的析构函数，因为是隐藏
		//Person::~Person();//正确用法不需要显式调用，结束会自动调用父类析构函数
		//实际上也不能显示调用调用父类的析构函数，因为子类析构函数结束后会自动调用父类析构函数，这样才能保证先析构子类，再析构父类
		cout << "~Student()" << endl;
	}
protected:
	int _stuid;
};	
int main()
{
	Student stu("chenran",2022);
	Student s2(stu);  //拷贝构造，父类的成员部分调用父类的拷贝构造函数

	Student s3 ;
	s3 = s2;
	return 0;
}
*/
//ps:如何设计一个不能被继承的类？把构造函数放在private里，这样子类就无法调用父类构造函数


//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员
/*class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
	//父类友元函数不会被继承，所以访问不了子类私有和保护成员
	//如果想访问，就在子类里再写一个友元函数
}
void main()
{
	Person p;
	Student s;
	Display(p, s);
}*/


//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。
//无论派生出多少个子类，都只有一个static成员实例。
/*class Person
{
public:
	Person() { ++_count; }
	string _name; // 姓名

	static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
int main()
{
	Person p;
	Student s;
	p._name = "www";
	s._name = "hhh";

	p._count = 1;
	s._count = 2;
	Person::_count++;
	cout << p._count << "  " << s._count << endl;
	return 0;
}*/


//多继承：一个子类有两个或以上直接父类时称这个继承关系为多继承
//菱形继承：菱形继承是多继承的一种特殊情况。
//菱形继承的问题：从下面的对象成员模型构造，可以看出菱形继承有数据冗余和二义性的问题。
//在Assistant的对象中Person成员会有两份。
/*class Person
{
public:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _num; //学号
};
class Teacher : public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void main()
{
	// 这样会有二义性无法明确知道访问的是哪一个
	Assistant a;
	a._name = "peter";
	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}*/
//虚拟继承可以解决菱形继承的二义性和数据冗余的问题。
//如上面的继承关系，在Student和Teacher的继承Person时使用虚拟继承，即可解决问题。
//需要注意的是，虚拟继承不要在其他地方去使用。
/*class Person
{
public:
	string _name; // 姓名
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
void main()
{
	Assistant a;
	a._name = "peter";
}*/

/*
class A
{
public:
	int _a;
};
 //class B : public A
class B : virtual public A
{
public:
	int _b;
};
 //class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl; //不用virtual时是20，使用virtual是24
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 3;  //继承的相同类共用一块空间，B、C的空间内存放着到相同类地址的偏移量的虚基表的地址
	return 0;
}*/


//继承与组合：
// public继承是一种is-a的关系。也就是说每个派生类对象都是一个基类对象。
//组合是一种has-a的关系。假设B组合了A，每个B对象中都有一个A对象。
// 优先使用对象组合，而不是类继承
// Car和BMW Car和Benz构成is-a的关系
class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
};
class BMW : public Car {
public:
	void Drive() { cout << "好开-操控" << endl; }
};
class Benz : public Car {
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};
// Tire和Car构成has-a的关系
class Tire {
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺寸
};
class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
};

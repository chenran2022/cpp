#include <iostream>
#include<cstdlib>
using namespace std;

//�������Ĭ�ϳ�Ա������
//���캯�����������캯����������������ֵ��������ء�ȡ��ַ��������ء�const���ε�ȡ��ַ���������

//�������const��Ա����

//class Date
//{
//public:
//	Date(int year=0, int month=1, int day=1)
// //ȫʡ����Ҳ��Ĭ�Ϲ��캯��
// //��������Ĭ��ֵ��ȱʡ������ָ��Ĭ��ֵ�Ĳ�������λ���β��б����Ҷˣ���������
// //ȱʡ���������ں��������Ͷ�����ͬʱ����,һ��ֻ�������г���
// //ȱʡֵ�����ǳ�������ȫ�ֱ�������һ�㲻ʹ��ȫ�ֱ����������̰߳�ȫ����
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
//	void print() const  //void print(const Date* this)  ����ֱ����()����д  const ���ε���thisָ����ָ��Ķ����������޸Ķ��������
//	{
//		cout << this->_year << endl;
//		//_year = 1;//�����޸Ķ���ĳ�Ա����
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
////Date& dǰ�����const���ٵ���d.print();
////ʵ������d.print(&d); &d��const Date* ,��Ա��������Ĭ����Date* this,void print(Date* this),����Ȩ�޵ķŴ���Ҫ�ڳ�Ա�����������const
//
//void fun(const Date& d)
//{
//	d.print();
//}
//int main()
//{
//	Date d1(12, 21, 2);
//	fun(d1);
//	d1.print();//Date* ����const Date* ,Ȩ����С������
//	return 0;
//}



//��Ա��������const��Ա����

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
//	//f1����f2����Ȩ����С
//	void f1()		//void f1(Date* this)
//	{
//		f2();		//this->f2(this)
//	}
//	void f2()const	//void f2(const Date* this)
//	{}
//
//
//	//f4����f3��Ȩ�޷Ŵ󣬳���
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
//	//ȡ��ַ���������
//	Date* operator&()
//	{
//		cout << "��constȡ��ַ���������" << endl;
//		return this;
//	}
//
//	//	constȡ��ַ���������
//	const Date* operator&()const
//	{
//		cout << "constȡ��ַ���������" << endl;
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



//�������������Ŀ�ģ����沿�� #define �궨�壻
////ʹ���������������ͨ������Ŀ�ģ���߳��������Ч�ʣ�
//C++�������ڶ�������к������Զ���Ϊ������������ʽ������
//������������Ҳ��һ�������ĺ�����������ͨ������������Ϊ��Ψһ��֮ͬ�������������������ʵ��ط���Ԥ�����һ��չ����
//�ڳ�������ʱ���ٽ��к������úͷ��أ��Ӷ������������úͷ��ص�ϵͳ����, ����˳���ִ��Ч�ʡ�


//ʲôʱ���Ա��������const����
//ֻҪ��Ա�����в�ֱ�ӻ����޸ĳ�Ա������ö�Ҫ����const
//��Ϊ����const֮�󲻹���const�����Ƿ�const���󶼿��Ե���



//��ʼ���б�
//const��Ա���������á��Զ������ͳ�Ա(û��Ĭ�Ϲ��캯��)  
//�����ֱ����ڳ�ʼ���б��ڳ�ʼ������Ϊ�����ֱ����ڶ����ʱ����г�ʼ��
//���԰ѳ�ʼ���б����Ϊ��Ա��������ĵط�
//����ʹ�ó�ʼ���б�ȥ��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������͵ĳ�Ա������һ������ʹ�ó�ʼ���б��ʼ��
//class A
//{
//public:
//	A(int a,int ref):_b(a),_i(ref),_n(10)
//	{
//		//��Ա�����Ķ���
//	}
//private:
//	//��Ա����������
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
//����ʹ�ó�ʼ���б�ȥ��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������͵ĳ�Ա������һ������ʹ�ó�ʼ���б��ʼ��

//��Ա���������Ĵ�����ǳ�ʼ���б�ĳ�ʼ��˳�������ڳ�ʼ���б���Ⱥ�����޹�
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
//	//������a2,���a1�����ڳ�ʼ���б���Ҳ���ȳ�ʼ��a2�������a1
//	
//};
//int main()
//{
//	A test(1);
//	test.print(); 
//	//_a1��1����_a2�����ֵ
//	//��Ա���������Ĵ�����ǳ�ʼ���б�ĳ�ʼ��˳�������ڳ�ʼ���б���Ⱥ�����޹�
//	return 0;
//}
//


//explicit  ��ֹ���캯��������ʽ����ת��

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
//	Date d1(1);//ֱ�ӹ���
//	Date d2 = 2;//��ʽ���͵�ת�� �����tmp(2),����tmp��������d2(tmp),Ȼ��������Ż���ֱ�ӹ���
//	const Date& d3 = 3; // ���þ����м��������ʱ����
//
//	Date d4 = d2;//��������
//
//	int i = 2;
//	const double& d = i;//��ʽ����ת����������м����ʱ����(���г����ԣ�
//
//	return 0;
//}

//C++11  �������
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
//	Date d1(1, 2, 3);//ֱ�ӹ���
//	Date d2 = { 2,3,4 };//��ʽ����ת����ʹ�û����ţ�C++11��֧��
//	return 0;
//}



//static��̬��Ա
//��̬��Ա�������������ⶨ��
//��̬��Ա�������ܷ��ʷǾ�̬��Ա
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
//		getn();//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����
//	}
//	static int getn() //��̬��Ա����û��thisָ�룬��ʹ�ö���Ϳ��Ե��ã����ܷ��ʷǾ�̬��Ա(��Ա�����ͳ�Ա����)
//	{
//		//_a = 1; //���ܷ��ʷǾ�̬��Ա(��Ա�����ͳ�Ա����)
//		return n;
//	}
//private:
//	int _a;
//	
//	static int n;//������������̬��Ա������ĳ����������������ж������������
//	//n���ڶ����У��ھ�̬��
//};
//int A::n = 0;  //���ⶨ��
//int main()
//{
//	A aa(1);
//	aa.f();
//	A aa2(2);
//	aa2.f();
//	//cout << a::n << endl;
//	cout << A::getn() << endl;//���þ�̬��Ա����
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
//	Sum a[10]; //���飬ÿһ��������һ�ι��캯��
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
//	//����ȱʡֵ�������ֵ������ʹ��������ȱʡֵ
//	A():_year(10)
//	{}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//C++11֧��
//	//�Ǿ�̬��Ա������������ʱ����Ը�ȱʡֵ
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



//��Ԫ

//��Ԫ�������Է������ڵ�˽�г�Ա�ͱ�����Ա����������ĳ�Ա����
// ��Ԫ����������const����
// ��Ԫ�����������ඨ����κεط����������ܷ����޶�������
// 
//class A
//{
//
//	//friend void operator<<(ostream& cout, const A& a);//��Ԫ�������Է������ڵ�˽�г�Ա
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
////��ʽ����
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
////��ʽ��������
//istream&  operator>>(istream& cin, A& a)
//{
//	cin >> a._year >> a._month >> a._day;
//	return cin;
//}
//int main()
//{
//	A a;
//	//cout << a;
//	//ʹ�ó�Ա�����������������Ϊthisָ��ռ��һλ����˫Ŀ�������ߵ�ֵ��
//	// �����cout��˳��ߵ����ɶ��Բ�,���Բ���ʹ�ó�Ա��������<<�����
//	a << cout;
//
//	cout << a;//��������ʽ����
//	
//	A a2(2, 2, 2);
//	cout << a << a2 << a << a2 << endl;
//
//	cin >> a2>>a;
//	cout << a2<<a;
//	return 0;
//}


//��Ԫ��

//class Time
//{
//	friend class Date;//��Ԫ����Է��ʵ�ǰ���˽�г�Ա�ͱ�����Ա
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


//�ڲ���
class A
{
public:
	A():_a(20)
	{}
	class B  //�ڲ�����������A����Ԫ�࣬���Է���A��˽�г�Ա�ͱ�����Ա
	{
	public:
		void fun(const A& a)
		{
			cout << a.k << endl;
			cout << k << endl;
			cout << a._a << endl;
		}
	};
private:
	int _a;
	static int k;
};
int A::k = 0;
int main()
{
	A a;
	A::B b;  //�����ڲ������
	b.fun(a);
	return 0;
}
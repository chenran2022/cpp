#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	///*
//	//C语言中我们用到的最频繁的输入输出方式就是scanf ()与printf()。
//	//scanf(): 从标准输入设备(键盘)读取数据，并将值存放在变量(内存)中。
//	//printf(): 将指定的文字/字符串(内存)输出到标准输出设备(屏幕)。
//	//注意宽度输出和精度输出控制。
//	//*/
//	//int a = 0;
//	//scanf("%d", &a);
//	//printf("%d ", a);
//
//	///*
//	//C++流是指信息从外部输入设备（如键盘）向计算机内部（如内存）输入和从内存向外部输出设备（显示器）输出的过程。
//	//这种输入输出的过程被形象的比喻为“流”。
//	//*/
//	//cin >> a;// cin是标准库中定义的istream 类型全局对象
//	//cin.operator>>(a); //库里实现的是>>重载
//
//	//cout << a;//cout是标准库中定义的ostream 类型全局对象
//	//cout.operator<<(a);
//	///*
//	//C++标准库提供了4个全局流对象cin、cout、cerr、clog，使用cout进行标准输出，即数据从内存流向控制台(显示器)。
//	//使用cin进行标准输入即数据通过键盘输入到程序中，同时C++标准库还提供了cerr用来进行标准错误的输出，
//	//以及clog进行日志的输出，cout、cerr、clog是ostream类的三个不同的对象，
//	//因此这三个对象现在基本没有区别，只是应用场景不同
//	//*/
//
//	////C++ cout和cin能自动识别对象类型，因为本质他是一个函数重载区分识别
//	//double d;
//	//cin >> a >> d;
//	//cout << a << d;
//
//
//	//在线OJ中的输入和输出：
//	string str;
//	while (cin >> str) 
//	//整行接收,按ctrl+z结束,^z之前不能有任何字符输入（回车除外）
//	//^z不会产生字符，所以更不会存储到输入缓冲区，缓冲区中没有^z的存在
//	{
//		/*
//		istream& operator>> (int& val);
//		explicit operator bool() const;
//		使用while(cin>>i)去流中提取对象数据时，调用的是operator>>，返回值是istream类型的对象，
//		那么这里可以做逻辑条件值，源自于istream的对象又调用了operator bool，
//		operator bool调用时如果接收流失败，或者有结束标志，则返回false
//		*/
//		cout << cin.operator bool() << endl;;
//	}
//	return 0;
//}


//文件IO流
#include<fstream> 

//stringstream，必须要包含头文件。在该头文件下，标准库三个类：
//istringstream、ostringstream 和 stringstream
#include<sstream>

//stringstream使用string类对象代替字符数组，可以避免缓冲区溢出的危险，
//而且其会对参数类型进行推演，不需要格式化控制，也不会出现格式化失败的风险，因此使用更方便，更安全
struct info
{
	string name;
	int age;
};
int main()
{
	//ofstream ofs("text.text");			//相当于C语言中的fopen(,"w")
	//ofs.write("hello",3);				//fwrite
	//ofs.put('c');						//fput
	//ofs.close();						//fclose

	//ifstream ifs("text.text");			//fopen(,"r")
	//cout << (char)ifs.get() << endl;	//fget
	////ifs.read();						//fread
	//ifs.close();

	
	/*
	//读写一个结构体
	//用起来跟cout和cin类似，非常方便，且可读性好。
	info ifo = { "chenran",20 };
	ofstream ofs("text.text");
	ofs << ifo.name << " ";//输入一个空白字符是因为ifstream>> 遇到空白字符才会停止，跟cin>>类似
	ofs << ifo.age; //这里会自动把整形转为字符串类型
	ofs.close();

	info tmp;
	ifstream ifs("text.text"); //注意，如果上面的ofstream没有close，是不能进行ifstream操作的
	ifs >> tmp.name; //ifstream>> 遇到空白字符才会停止，跟cin>>类似
	ifs >> tmp.age;	//这里会自动把字符串类型转为整形
	ifs.close();

	cout << tmp.name << endl << tmp.age << endl;
	*/

	
	info ifo = { "chenran",20 };
	//序列化成字符串
	ostringstream ost;
	ost << ifo.name << endl;//通过输入空白字符可以让istringstream进行解析
	ost << ifo.age << endl;

	string str1 = ost.str();//返回ostringstream其底层的string对象。
	//网络中就可以把这个str1发送给另一端
	cout << str1;

	ost.clear();
			
	info tmp;
	istringstream iss;
	iss.str(str1);
	//网络另一端接收到以后就可以解析数据
	//反序列化
	iss >> tmp.name >> tmp.age;

	cout << tmp.name << endl << tmp.age << endl;
	return 0;
}

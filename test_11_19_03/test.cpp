#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test()
{
	//1.包含头文件
	
	//2.创建流对象
	ofstream ofs;
	//3.打开文件
	ofs.open("test.txt", ios::out | ios::binary);
	//4.读写文件
	Person p = { "张三", 18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5.关闭文件
	ofs.close();
}
void test1()
{
	//1.包含头文件

	//2.创建流对象
	ifstream ifs;
	//3.打开文件
	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4.读写文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	//5.关闭文件
	ifs.close();
	cout << p.m_Name << endl<<p.m_Age << endl;
}

int main()
{
	test();
	test1();
	system("pause");
	return 0;
}
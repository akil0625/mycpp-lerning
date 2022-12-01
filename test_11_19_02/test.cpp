#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//
void test()
{
	//1.包含头文件
	
	//2.创建流对象

	ifstream ifs;

	//3.打开文件 并判断是否打开成功

	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读文件
	//方法1
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/
	//方法2 
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, 1024))
	{
		cout << buf << endl;
	}*/
	//方法3
	/*string buf;

	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//方法4
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	cout << endl;
	//5.关闭文件
	ifs.close();
}

int main()
{
	test();
	system("pause");
	return 0;
}
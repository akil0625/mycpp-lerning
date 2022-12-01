#include <iostream>
//1.包含头文件
#include <fstream>
using namespace std;
//本节内容:写文件

void test()
{
	//ofstream:写操作
	//ifstream:读操作
	//fstream :读写操作
	//2.创建流对象
	ofstream ofs;
	//3.打开文件
	ofs.open("test.txt", ios::out);
	//4.写文件
	ofs << "姓名:张四" << endl;
	ofs << "性别:男" << endl;
	ofs << "年龄:十八" << endl;
	//5.关闭文件
	ofs.close();
}

int main()
{
	test();
	system("pause");
	return 0;
}
//写文件操作
//1.包含头文件
// #include<fstream>
//2.创建流对象
// ofstream ofs;
//3.打开文件
// ofs.open("文件路径", 打开方式)
//4.写数据
// ofs<<"写入的数据"
//5.关闭文件
//ofs.cluse();
#include <iostream>
using namespace std;
#include <string>

//string 字符获取

void test01()
{
	string str1 = "hello";
	//cout << str1 << endl;
	
	//1、通过 [] 获取单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i];
	}
	cout << endl;

	//2、通过 at 的方式获取单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i);
	}
	cout << endl;

	//1、通过 [] 修改单个字符
	str1[0] = 'm';
	cout << str1 << endl;

	//2、通过 at 的方式修改单个字符
	str1.at(0) = 'h';
	cout << str1 << endl;
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
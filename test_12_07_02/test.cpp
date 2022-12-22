#include <iostream>
using namespace std;
#include <string>

//string 字符串的比较

//比较方式:按照ASCII码值的大小比较
//1、前者大 返回 1
//2、后者大 返回 -1
//3、两者相等 返回 0


void test01()
{
	string str1 = "hello";
	string str2 = "hello";

	//输出返回值

	cout << str1.compare(str2) << endl;
	if (str1.compare(str2) == 0)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}
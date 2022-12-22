#include <iostream>
using namespace std;
#include <string>

//从字符串中获得字串

void test01()
{

	string str = "abcdefg";
	//从第几个字符开始截取多少个
	string str1 = str.substr(1, 2);
	cout << str1 << endl;

	//在邮箱帐号上的应用
	string email = "akil0612@qq.com";
	cout << email.substr(0, email.rfind('@')) << endl;

}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
#include <string>

//string的本质是一个类


int main()
{
	string s1;//默认构造创建一个类型

	const char* str = "hello world";//创建一个c风格的字符串

	string s2(str);//有参构造一个字符串类型

	string s3(s2);//拷贝构造一个字符串类型

	string s4(10, 'a');//多个重复字符

	
	cout << s1 <<endl
		<< s2 <<endl
		<< s3 <<endl
		<< s4;

	system("pause");
	return 0;
}

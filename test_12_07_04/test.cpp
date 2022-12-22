#include <iostream>
using namespace std;
#include <string>

//string 插入和删除

void test01()
{
	string str1 = "hello";
	
	//在第几个位置插入什么
	str1.insert(1, "###");
	
	//第几个位置开始删除多少个
	str1.erase(1, 2);
	
	cout << str1 << endl;
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
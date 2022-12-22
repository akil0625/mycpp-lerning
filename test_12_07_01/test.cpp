#include <iostream>
using namespace std;
#include <string>

//字符串的查找和替换

//1、查找
void test01()
{

	//find//从左边开始查找
	string str1 = "abcdefg";
	int pos = str1.find("de");//能找到目标时返回位置(下标)，没有找到时返回-1
	cout << " find找到的pos = " << pos << endl;

	//rfind//从右边开始查找
	pos = str1.rfind("de");
	cout << "rfind找到的pos = " << pos << endl;

}

//2、替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "muamuamua");//删除1-3号下标的字符，再将指定字符插入
	cout << "替换后的结果为 : " << str1 << endl;
}

//主函数
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
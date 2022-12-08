#include <iostream>
#include <string>
using namespace std;

//普通函数与函数模板的调用规则
//1.如果普通函数与模板函数都可以调用，则优先调用模板函数
//2.可以通过空模板参数列表强制调用模板函数
//3.模板函数可以发生函数重载
//4.如果函数模板可以产生更好的匹配，则优先调用函数模板

//普通函数
void myPrint(int a, int b)
{
	cout << "调用了普通函数" << endl;
}

//函数模板
template<typename T>
void myPrint(T a ,T b)
{
	cout << "调用了函数模板" << endl;
}

//函数模板发生重载
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用了重载的函数模板" << endl;
}

//测试函数
void test()
{
	int a = 0;
	int b = 0;
	int c = 0;

	char d = 'd';
	char e = 'e';

	//都可以调用时，调用普通函数(与普通函数是否定义无关)
	myPrint(a, b);

	//通过空的模板参数列表，可以强行调用函数模板
	myPrint<>(a, b);

	//调用发生重载的函数模板&&如果函数模板可以更好的匹配则有限调用函数模板
	myPrint(a, b, c);

	//如果函数模板可以更好的匹配则有限调用函数模板
	myPrint(d, e);
}

//主函数
int main()
{
	test();
	system("pause");
	return 0;
}
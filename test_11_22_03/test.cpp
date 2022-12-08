#include <iostream>
#include <string>
using namespace std;

//普通函数与模板函数的区别

//1.普通函数调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型，可以发生类型转换

//普通函数
int myAdd(int a, int b)
{
	return a + b;
}

//函数模板
template<typename T>
T myAddt(T a, T b)
{
	return a + b;
}

void test()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//普通函数
	cout << myAdd(a, b) << endl;
	//可发生隐式类型转换
	cout << myAdd(a, c) << endl;
	//函数模板
	cout << myAddt(a, b) << endl;
	//自动类型推导，不可发生隐式类型转换
	//cout << myAddt(a, c);//报错
	//用显示推到类型，可发生类型转换
	cout << myAddt<int>(a, c) << endl;
	//随意变换
	cout << myAddt<char>(a, c) << endl;
	cout << myAddt<char>(b, c) << endl;
}

//主函数
int main()
{
	test();
	system("pause");
	return 0;
}
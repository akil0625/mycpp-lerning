#include <iostream>
#include <string>
using namespace std;

//类模板分文件编写遇到的问题及解决方案

//第一种解决方式:直接包含源文件
//#include "Person.cpp"

//第二种解决方式:将.h文件与.cpp文件内容写在一起，将后缀名改为.hpp
#include "Person.hpp"

void test1()
{
	Person<string, int>p("akil", 20);
	p.showPerson();
}

int main()
{
	test1();
	system("pause");
	return 0;
}
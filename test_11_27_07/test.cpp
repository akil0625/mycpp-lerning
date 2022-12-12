#include <iostream>
using namespace std;
#include "MyArray.hpp"
//类模板案例

/*
要求:
可以对内置的数据类型以及自定义数据类型进行存储
将数组中的数据存储到栈区
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及重载赋值运算符以防止浅拷贝问题
提供尾插法和尾删法对数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获得当前数组中的元素个数以及数组容量
*/

//每种自定义类型的元素列出都要写出列出方式
void PrintArr(MyDataManager<Person>&arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << "姓名;" << arr[i].m_Neme << endl
			<< "年龄;" << arr[i].m_Age << endl;
	}
}

//测试函数
void test()
{
	//创建数组
	MyDataManager<Person>mdm(5);
	//创建元素
	Person p1("akil", 20);
	Person p2("abdusalam", 26);
	Person p3("sultan", 20);
	//存入元素
	mdm.Push_Back(p1);
	mdm.Push_Back(p3);
	mdm.Push_Back(p2);
	//显示数组内容
	cout << "arr1的打印值为:" << endl;
	PrintArr(mdm);
	cout << "arr1的容量为:"<<mdm.GetCapacity() << endl;
	cout << "arr1的元素数量为:" << mdm.GetSize() << endl;

}

//主函数
int main()
{
	test();
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
#include <vector>

//vector与普通数组的区别
/*
1.可动态扩展空间
2.利用迭代器控制
*/

//vector容器的构造

//自制打印
void printvector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}

void test01()
{
	//创建vector容器
	vector<int>v1;//-----------默认构造
	//放入数据
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);

	//创建vector容器
	vector<int>v2(v1.begin(), v1.end());//----------区间构造
	printvector(v2);

	//创建vector容器
	vector<int>v3(10, 100);//-------多少个什么的方式构造
	printvector(v3);

	//创建一个vector容器
	vector<int>v4(v3);//拷贝构造
	printvector(v4);
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
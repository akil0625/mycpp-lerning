#include <iostream>
using namespace std;
#include <vector>

// vector 的插入和删除

//遍历
void vprint(vector<int>&v)
{
	if (v.empty())
	{
		cout << "该容器为空" << endl;
		return;
	}
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	vprint(v1);
	
	//尾删
	v1.pop_back();
	vprint(v1);

	//插入  
	//1、(第一个参数是迭代器)
	v1.insert(v1.begin()+4, 50);
	vprint(v1);

	//2、从第几个位置开始插入多少个什么
	v1.insert(v1.begin() + 5, 10, 100);
	vprint(v1);

	//删除
	//1、(第一个参数为迭代器)
	v1.erase(v1.begin() + 5);
	vprint(v1);

	//2、区间的方式删除
	v1.erase(v1.begin(), v1.end());//等同于clear
	vprint(v1);

}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
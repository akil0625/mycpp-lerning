#include <iostream>
#include <string>
using namespace std;

//实现通用数据类型的排序
//规则 从小到大
//算法 冒泡排序
//测试 char数组，int数组

//升序排序模板函数
template<typename T>
void mySort1(T arr[], int len)
{
	for (int i = len; i > 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//降序排序模板函数
template<typename T>
void mySort2(T arr[], int len)
{
	for (int i = len; i > 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	char a[] = "askldjghsdf";
	int b[] = { 9,6,4,9,4,1,5,2,3,9,4,1 };

	//字符串的升序排序
	mySort1<char>(a, strlen(a));
	cout << a << endl;

	//数组的升序排序
	mySort1<int>(b, sizeof(b) / sizeof(int));
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << b[i];
	}
	cout << endl;

	//字符串的降序排序
	mySort2<char>(a, strlen(a));
	cout << a << endl;

	//数组的降序排序
	mySort2<int>(b, sizeof(b) / sizeof(int));
	for (int i = 0; i < sizeof(b) / sizeof(int); i++)
	{
		cout << b[i];
	}
	cout << endl;

	system("pause");
	return 0;
}
#pragma once
#include <iostream>
using namespace std;
#include <string>

//自定义的类型
class Person
{
public:
	Person()
	{
		this->m_Age = 0;
	}
	Person(string name,int age)
	{
		this->m_Neme = name;
		this->m_Age = age;
	}
	string m_Neme;
	int m_Age;
};

//可以存储各种类型的元素的顺序表(模板参数列表中需要传入数据类型)
template<class T>
class MyDataManager
{
public:

	//构造函数
	MyDataManager(int capacity)
	{
		//cout << "有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];
	}

	//拷贝构造   //防止浅拷贝
	MyDataManager(const MyDataManager& arr)
	{
		//cout << "拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pArray = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pArray[i] = arr.pArray[i];
		}
	}

	//尾插法
	void Push_Back(const T& val)
	{

		//判断是否要满
		if (this->m_Capacity == this->m_Size)
		{
			cout << "已满" << endl;
			return;
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;//更新元素数目
	}

	//尾删法
	void Pop_Back()
	{

		//判断是否为空
		if (this->m_Size == 0)
		{
			cout << "此表为空" << endl;
			return;
		}

		//逻辑上的删除
		this->m_Size--;
	}

	//根据下标得到数据
	T & operator[](int pos)
	{
		return this->pArray[pos];
	}

	//得到数组容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//得到元素数量
	int GetSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyDataManager()
	{
		//cout << "析构函数调用" << endl;
		if (this->pArray != NULL)
		{
			delete[] this->pArray;
			this->pArray = NULL;
		}
	}

	//重载赋值运算符  //防止浅拷贝
	MyDataManager & operator=(const MyDataManager& arr)
	{
		//cout << "赋值等号" << endl;
		if (this->pArray != NULL)
		{
			delete[] this->pArray;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pArray = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pArray[i] = arr.pArray[i];
		}
		return *this;
	}

private:
	//指向数组空间
	T * pArray;
	//最大容量
	int m_Capacity;
	//元素数量
	int m_Size;
};
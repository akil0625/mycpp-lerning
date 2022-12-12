#pragma once
#include <iostream>
using namespace std;
#include <string>

//�Զ��������
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

//���Դ洢�������͵�Ԫ�ص�˳���(ģ������б�����Ҫ������������)
template<class T>
class MyDataManager
{
public:

	//���캯��
	MyDataManager(int capacity)
	{
		//cout << "�вι���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pArray = new T[this->m_Capacity];
	}

	//��������   //��ֹǳ����
	MyDataManager(const MyDataManager& arr)
	{
		//cout << "��������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pArray = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pArray[i] = arr.pArray[i];
		}
	}

	//β�巨
	void Push_Back(const T& val)
	{

		//�ж��Ƿ�Ҫ��
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����" << endl;
			return;
		}
		this->pArray[this->m_Size] = val;
		this->m_Size++;//����Ԫ����Ŀ
	}

	//βɾ��
	void Pop_Back()
	{

		//�ж��Ƿ�Ϊ��
		if (this->m_Size == 0)
		{
			cout << "�˱�Ϊ��" << endl;
			return;
		}

		//�߼��ϵ�ɾ��
		this->m_Size--;
	}

	//�����±�õ�����
	T & operator[](int pos)
	{
		return this->pArray[pos];
	}

	//�õ���������
	int GetCapacity()
	{
		return this->m_Capacity;
	}
	//�õ�Ԫ������
	int GetSize()
	{
		return this->m_Size;
	}

	//��������
	~MyDataManager()
	{
		//cout << "������������" << endl;
		if (this->pArray != NULL)
		{
			delete[] this->pArray;
			this->pArray = NULL;
		}
	}

	//���ظ�ֵ�����  //��ֹǳ����
	MyDataManager & operator=(const MyDataManager& arr)
	{
		//cout << "��ֵ�Ⱥ�" << endl;
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
	//ָ������ռ�
	T * pArray;
	//�������
	int m_Capacity;
	//Ԫ������
	int m_Size;
};
#include <iostream>
using namespace std;
#include "MyArray.hpp"
//��ģ�尸��

/*
Ҫ��:
���Զ����õ����������Լ��Զ����������ͽ��д洢
�������е����ݴ洢��ջ��
���캯���п��Դ������������
�ṩ��Ӧ�Ŀ������캯���Լ����ظ�ֵ������Է�ֹǳ��������
�ṩβ�巨��βɾ�������ݽ������Ӻ�ɾ��
����ͨ���±�ķ�ʽ���������е�Ԫ��
���Ի�õ�ǰ�����е�Ԫ�ظ����Լ���������
*/

//ÿ���Զ������͵�Ԫ���г���Ҫд���г���ʽ
void PrintArr(MyDataManager<Person>&arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << "����;" << arr[i].m_Neme << endl
			<< "����;" << arr[i].m_Age << endl;
	}
}

//���Ժ���
void test()
{
	//��������
	MyDataManager<Person>mdm(5);
	//����Ԫ��
	Person p1("akil", 20);
	Person p2("abdusalam", 26);
	Person p3("sultan", 20);
	//����Ԫ��
	mdm.Push_Back(p1);
	mdm.Push_Back(p3);
	mdm.Push_Back(p2);
	//��ʾ��������
	cout << "arr1�Ĵ�ӡֵΪ:" << endl;
	PrintArr(mdm);
	cout << "arr1������Ϊ:"<<mdm.GetCapacity() << endl;
	cout << "arr1��Ԫ������Ϊ:" << mdm.GetSize() << endl;

}

//������
int main()
{
	test();
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
#include <vector>

// vector �Ĳ����ɾ��

//����
void vprint(vector<int>&v)
{
	if (v.empty())
	{
		cout << "������Ϊ��" << endl;
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
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	vprint(v1);
	
	//βɾ
	v1.pop_back();
	vprint(v1);

	//����  
	//1��(��һ�������ǵ�����)
	v1.insert(v1.begin()+4, 50);
	vprint(v1);

	//2���ӵڼ���λ�ÿ�ʼ������ٸ�ʲô
	v1.insert(v1.begin() + 5, 10, 100);
	vprint(v1);

	//ɾ��
	//1��(��һ������Ϊ������)
	v1.erase(v1.begin() + 5);
	vprint(v1);

	//2������ķ�ʽɾ��
	v1.erase(v1.begin(), v1.end());//��ͬ��clear
	vprint(v1);

}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}
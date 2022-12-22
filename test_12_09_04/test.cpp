#include <iostream>
using namespace std;
#include <deque>

//deque�����Ĳ����ɾ��

//deque<int>��������ʾ����
void dprint(const deque<int>& d)
{
	if (d.empty())
	{
		cout << "empty" << endl;
		return;
	}
	cout << "��СΪ:" << d.size() << endl;
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d1;
	
	//β��
	d1.push_back(10);
	d1.push_back(20);
	dprint(d1);

	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	dprint(d1);

	//βɾ
	d1.pop_back();
	dprint(d1);

	//ͷɾ
	d1.pop_front();
	dprint(d1);
}

void test02()
{
	//��������
	deque<int>d1;
	d1.push_back(10);  //��
	d1.push_back(20);  //��
	d1.push_front(100);//Ԫ
	d1.push_front(200);//��
	dprint(d1);
	deque<int>d2(d1);

	//����Ԫ��
	d1.insert(d1.begin()+2, 500);//��һ������Ϊ���������ڶ���Ϊelm
	dprint(d1);

	//����n��Ԫ��
	d1.insert(d1.begin() + 2, 2, 500);//��һ������Ϊ���������ڶ���Ϊelm
	dprint(d1);

	//����һ������
	d1.insert(d1.begin(), d2.begin(), d2.end());//��ʲôλ�ü���ʲô����
	dprint(d1);
}

void test03()
{
	//��������
	deque<int>d1;
	d1.push_back(10);  //��
	d1.push_back(20);  //��
	d1.push_front(100);//Ԫ
	d1.push_front(200);//��
	dprint(d1);
	
	//ɾ��
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	dprint(d1);

	//���䷽ʽɾ��
	d1.erase(d1.begin() + 1, d1.end());//����Ϊ����������
	dprint(d1);

	//���
	d1.clear();
	dprint(d1);
}

//������
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
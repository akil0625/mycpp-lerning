#include <iostream>
using namespace std;
#include <string>

//string �����ɾ��

void test01()
{
	string str1 = "hello";
	
	//�ڵڼ���λ�ò���ʲô
	str1.insert(1, "###");
	
	//�ڼ���λ�ÿ�ʼɾ�����ٸ�
	str1.erase(1, 2);
	
	cout << str1 << endl;
}

//������
int main()
{
	test01();
	system("pause");
	return 0;
}
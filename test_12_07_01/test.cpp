#include <iostream>
using namespace std;
#include <string>

//�ַ����Ĳ��Һ��滻

//1������
void test01()
{

	//find//����߿�ʼ����
	string str1 = "abcdefg";
	int pos = str1.find("de");//���ҵ�Ŀ��ʱ����λ��(�±�)��û���ҵ�ʱ����-1
	cout << " find�ҵ���pos = " << pos << endl;

	//rfind//���ұ߿�ʼ����
	pos = str1.rfind("de");
	cout << "rfind�ҵ���pos = " << pos << endl;

}

//2���滻
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "muamuamua");//ɾ��1-3���±���ַ����ٽ�ָ���ַ�����
	cout << "�滻��Ľ��Ϊ : " << str1 << endl;
}

//������
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
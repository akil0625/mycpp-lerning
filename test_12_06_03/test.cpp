
#include <iostream>

using namespace std;

#include <stdio.h>


//string�ַ���ƴ��


/*

��׷��char*���ͺ�string���ͺ͵�������

����+=���ź�appand()��ʽ׷��

appand()����ָ��׷����Դ��׷��λ�ã�׷�ӳ���

*/


void test01()
{
	//׷��char*����
	string str1;
	str1 += "����";
	str1 += ",";

	//׷��string����
	string str2 = "�Ұ�����Ϸ";
	str1 += str2;
	cout << str1 << endl;

	//��Ա������ʽ׷��
	string str3 = "I";
	str3.append(" LOVE ");
	str3.append("GAME");
	cout << str3 << endl;

	//�޶�׷�ӳ���
	string str4;
	str4 += str3;
	str4.append("ahdfasgkasdg",1);
	cout << str4 << endl;

	//appand��ʽ׷��
	string str5 ="\?";
	str5.append(str4);
	cout << str5 << endl;

	//��λ��׷�Ӷ��ٸ�
	string str6;
	str6.append(str3, 0, 6);
	cout << str6 << endl;

}

//������
int main()
{

	//why noone understand
	
	//why I don`t have friend that know me even my family 
	
	test01();
	
	system("pause");
	
	return 0;

}


#include <iostream>

using namespace std;

#include <stdio.h>


//string字符串拼接


/*

可追加char*类型和string类型和单个符号

可用+=符号和appand()方式追加

appand()可以指定追加来源，追加位置，追加长度

*/


void test01()
{
	//追加char*类型
	string str1;
	str1 += "哈哈";
	str1 += ",";

	//追加string类型
	string str2 = "我爱玩游戏";
	str1 += str2;
	cout << str1 << endl;

	//成员函数方式追加
	string str3 = "I";
	str3.append(" LOVE ");
	str3.append("GAME");
	cout << str3 << endl;

	//限定追加长度
	string str4;
	str4 += str3;
	str4.append("ahdfasgkasdg",1);
	cout << str4 << endl;

	//appand方式追加
	string str5 ="\?";
	str5.append(str4);
	cout << str5 << endl;

	//按位置追加多少个
	string str6;
	str6.append(str3, 0, 6);
	cout << str6 << endl;

}

//主函数
int main()
{

	//why noone understand
	
	//why I don`t have friend that know me even my family 
	
	test01();
	
	system("pause");
	
	return 0;

}

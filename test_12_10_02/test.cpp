#include <iostream>
using namespace std;
#include <stack>

//ջstack����

int main()
{
	//�ص�:�����Ƚ���������ݽṹ
	stack<int>s;

	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	//ֻҪ��Ϊ�գ��鿴ջ������ִ�г�ջ
	while (!s.empty())
	{
		cout << s.top() << endl;
		//��ջ
		s.pop();
	}

	system("pause");
	return 0;
}
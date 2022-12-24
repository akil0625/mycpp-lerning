#include <iostream>
using namespace std;
#include <stack>

//栈stack容器

int main()
{
	//特点:符合先进后出的数据结构
	stack<int>s;

	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	//只要不为空，查看栈顶，并执行出栈
	while (!s.empty())
	{
		cout << s.top() << endl;
		//出栈
		s.pop();
	}

	system("pause");
	return 0;
}
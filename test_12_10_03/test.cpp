#include <iostream>
using namespace std;
#include <queue>

//队列queue容器

class Person
{
public:

	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;

	}
	string m_Name;
	int m_Age;
};


void test01()
{
	//创建容器
	queue<Person>q;
	//创建元素
	Person p1("akil", 20);
	Person p2("abdusalam", 26);
	Person p3("sultan", 20);
	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	while (!q.empty())
	{
		cout << "姓名:" << q.front().m_Name << "	年龄:"<<q.front().m_Age << endl;
		//出队
		q.pop();
	}
}

//主函数
int main()
{
	test01();
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
//继承后的子类大小
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son :public Base
{

public:
	int m_D;
};
//父类中所有非静态的成员都会被子类继承下来，只是部分无法访问






int main()
{
	cout << sizeof(Son) << endl;
	system("pause");
	return 0;
}
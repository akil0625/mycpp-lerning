#include <iostream>
#include <string>
using namespace std;
//�̳к�������С
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
//���������зǾ�̬�ĳ�Ա���ᱻ����̳�������ֻ�ǲ����޷�����






int main()
{
	cout << sizeof(Son) << endl;
	system("pause");
	return 0;
}
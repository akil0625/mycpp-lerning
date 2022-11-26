#include <iostream>
using namespace std;
#include <string>



class Circle
{
public:
	void setX(int a)
	{
		m_X = a;
	}
	void setY(int a)
	{
		m_Y = a;
	}
	void setR(int a)
	{
		while(1)
		{
			if (a > 0)
			{
				m_R = a;
				break;
			}
			else
				cout<< "��������Чֵ\n";
		}
		
		
	}
	int getX()
	{
		return m_X;
	}
	int getY()
	{
		return m_Y;
	}
	int getR()
	{
		return m_R;
	}
	//int checkPoint(Point p)
	//{
	//	return (p.getX() - m_X) * (p.getX() - m_X) + (p.getY() - m_Y) * (p.getY() - m_Y) - m_R * m_R;
	//}



private:
//Բ������
	int m_X;
	int m_Y;
//�뾶
	int m_R;
};

class Point
{

public:
	void setX(int a)
	{
		m_X = a;
	}
	void setY(int a)
	{
		m_Y = a;
	}
	int getX()
	{
		return m_X;
	}
	int getY()
	{
		return m_Y;
	}
	int checkCir(Circle c)
	{
		return (m_X - c.getX()) * (m_X - c.getX()) + (m_Y - c.getY()) * (m_Y - c.getY()) - c.getR() * c.getR();
	}

private:
//����
	int m_X;
	int m_Y;
};

int checkPos(Point p, Circle c)
{
	//����ֵ�����������Բ��
	//����ֵ�����������Բ��
	//����ֵС���������Բ��
	return (p.getX() - c.getX()) * (p.getX() - c.getX()) + (p.getY() - c.getY()) * (p.getY() - c.getY()) - c.getR() * c.getR();
}



int main()
{
	Circle c;
	Point p;
	p.setX(3);
	p.setY(4);
	c.setX(0);
	c.setY(0);
	c.setR(5);
	if(checkPos(p, c)>0)
		cout<<"����Բ��\n";
	else if (checkPos(p, c) < 0)
		cout << "����Բ��\n";
	else if (checkPos(p, c) == 0)
		cout << "����Բ��\n";
	p.setX(3);
	p.setY(4);
	c.setX(0);
	c.setY(0);
	c.setR(5);
	if (p.checkCir(c) > 0)
		cout << "����Բ��\n";
	else if (p.checkCir(c) < 0)
		cout << "����Բ��\n";
	else if (p.checkCir(c) == 0)
		cout << "����Բ��\n";
	system("pause");
	return 0;
}
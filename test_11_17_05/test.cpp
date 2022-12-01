#include <iostream>
#include <string>
using namespace std;
//��̬����-������װ
//˼·:�������Դ�ڲ�ͬ�ĳ���


//CPU
class CPU
{
public:
	virtual void calculator() = 0;
};
//�Կ�
class VideoCard
{
public:
	virtual void display() = 0;
};
//�ڴ�
class Memory
{
public:
	virtual void storage() = 0;
};
class Computer
{
public:
	//��װ����
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory)
	{
		m_cpu = cpu;
		m_videocard = videocard;
		m_memory = memory;
	}
	//��������
	void work()
	{
		//��������ýӿں���
		m_cpu->calculator();
		m_videocard->display();
		m_memory->storage();
	}
	//������������
	Computer()
	{
		if (m_cpu != NULL)
			delete m_cpu;
		m_cpu = NULL;
		if (m_videocard != NULL)
			delete m_videocard;
		m_videocard = NULL;
		if (m_memory != NULL)
			delete m_memory;
		m_memory = NULL;
	}
private:
	CPU* m_cpu;//CPU��ָ��
	VideoCard* m_videocard;//�Կ���ָ��
	Memory* m_memory;//�ڴ�����ָ��
};
//Ӣ�ض�������
class IntelCPU :public CPU
{
public:
	void calculator()
	{
		cout << "Ӣ�ض��Ĵ�������ʼ������" << endl;
	}
};
//���봦����
class LenovoCPU :public CPU
{
public:
	void calculator()
	{
		cout << "����Ĵ�������ʼ������" << endl;
	}
};
//Lenovo�Կ�
class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "�����Կ���ʼ������" << endl;
	}
};
//akil���Կ�
class AkilVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "akil���Կ���ʼ������" << endl;
	}
};
class AnyMemory :public Memory
{
public:
	void storage()
	{
		cout << "�����ڴ�����ʼ������" << endl;
	}
};

void test()
{
	CPU* cpu = new LenovoCPU;
	VideoCard* videocard= new AkilVideoCard;
	Memory* memory = new AnyMemory;
	Computer* computer = new Computer(cpu, videocard, memory);
	cout << "��һ̨���Կ�ʼ����" << endl;
	computer->work();
	delete computer;
	cout << "��һ̨���Թػ�" << endl;
}
void test1()
{
	CPU* cpu = new IntelCPU;
	VideoCard* videocard = new LenovoVideoCard;
	Memory* memory = new AnyMemory;
	Computer* computer = new Computer(cpu, videocard, memory);
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	computer->work();
	delete computer;
	cout << "�ڶ�̨���Թػ�" << endl;
}
void test2()
{
	Computer* computer = new Computer(new IntelCPU, new AkilVideoCard, new AnyMemory);
	cout << "����̨���Կ�ʼ����" << endl;
	computer->work();
	delete computer;
	cout << "����̨���Թػ�" << endl;
}

int main()
{
	cout << "------------------------" << endl;
	test();
	cout << "------------------------" << endl;
	test1();
	cout << "------------------------" << endl;
	test2();
	cout << "------------------------" << endl;
	system("pause");
	return 0;
}
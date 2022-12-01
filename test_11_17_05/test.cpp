#include <iostream>
#include <string>
using namespace std;
//多态案例-电脑组装
//思路:各零件来源于不同的厂商


//CPU
class CPU
{
public:
	virtual void calculator() = 0;
};
//显卡
class VideoCard
{
public:
	virtual void display() = 0;
};
//内存
class Memory
{
public:
	virtual void storage() = 0;
};
class Computer
{
public:
	//组装电脑
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory)
	{
		m_cpu = cpu;
		m_videocard = videocard;
		m_memory = memory;
	}
	//工作函数
	void work()
	{
		//让零件调用接口函数
		m_cpu->calculator();
		m_videocard->display();
		m_memory->storage();
	}
	//电脑析构函数
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
	CPU* m_cpu;//CPU的指针
	VideoCard* m_videocard;//显卡的指针
	Memory* m_memory;//内存条的指针
};
//英特尔处理器
class IntelCPU :public CPU
{
public:
	void calculator()
	{
		cout << "英特尔的处理器开始工作了" << endl;
	}
};
//联想处理器
class LenovoCPU :public CPU
{
public:
	void calculator()
	{
		cout << "联想的处理器开始工作了" << endl;
	}
};
//Lenovo显卡
class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "联想显卡开始工作了" << endl;
	}
};
//akil的显卡
class AkilVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "akil的显卡开始工作了" << endl;
	}
};
class AnyMemory :public Memory
{
public:
	void storage()
	{
		cout << "随便的内存条开始工作了" << endl;
	}
};

void test()
{
	CPU* cpu = new LenovoCPU;
	VideoCard* videocard= new AkilVideoCard;
	Memory* memory = new AnyMemory;
	Computer* computer = new Computer(cpu, videocard, memory);
	cout << "第一台电脑开始工作" << endl;
	computer->work();
	delete computer;
	cout << "第一台电脑关机" << endl;
}
void test1()
{
	CPU* cpu = new IntelCPU;
	VideoCard* videocard = new LenovoVideoCard;
	Memory* memory = new AnyMemory;
	Computer* computer = new Computer(cpu, videocard, memory);
	cout << "第二台电脑开始工作" << endl;
	computer->work();
	delete computer;
	cout << "第二台电脑关机" << endl;
}
void test2()
{
	Computer* computer = new Computer(new IntelCPU, new AkilVideoCard, new AnyMemory);
	cout << "第三台电脑开始工作" << endl;
	computer->work();
	delete computer;
	cout << "第三台电脑关机" << endl;
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
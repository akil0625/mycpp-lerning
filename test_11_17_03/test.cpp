#include <iostream>
#include <string>
using namespace std;
//制作饮品
class Drink
{
public:
	//烧开水
	virtual void boil() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒入杯中
	virtual void pourInCup() = 0;
	//加入佐料
	virtual void putSomething() = 0;
	

	//制作
	void makeDrink()
	{
		//烧开水
		boil();
		//冲泡
		brew();
		//倒入杯中
		pourInCup();
		//加入佐料
		putSomething();
	}

};
class Coffee :public Drink
{
	//烧开水
	virtual void boil()
	{
		cout << "烧开农夫山泉" << endl;
	}
	//冲泡
	virtual void brew()
	{
		cout << "倒入咖啡" << endl;
	}
	//倒入杯中
	virtual void pourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入佐料
	virtual void putSomething()
	{
		cout << "倒入糖和牛奶" << endl;
	}
};
class Tea :public Drink
{
	//烧开水
	virtual void boil()
	{
		cout << "烧开百岁山" << endl;
	}
	//冲泡
	virtual void brew()
	{
		cout << "倒入茶叶" << endl;
	}
	//倒入杯中
	virtual void pourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入佐料
	virtual void putSomething()
	{
		cout << "倒入枸杞" << endl;
	}
};
void doWork(Drink* abc)
{
	abc->makeDrink();
	delete abc;
}
void test()
{
	//泡咖啡
	doWork(new Coffee);
	cout << "--------------------------" << endl;
	//泡茶
	doWork(new Tea);
}

int main()
{
	test();
	system("pause");
	return 0;
}

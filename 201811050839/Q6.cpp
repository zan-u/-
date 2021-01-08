#include <stdio.h>
#include <iostream>
using namespace std;
class vehicle     //基类的定义
{
protected:      //保护成员定义
	int wheels;
	double weight;
public:
	vehicle (int a, double b);    //获取车轮数量和车重的赋值
	int GetWheels() { return wheels; }   //获取车轮数量
	double GetWeight() { return weight; }    //获取车子的重量
	void show();
};
vehicle ::vehicle(int a, double b)
{
	wheels = a;
	weight = b;
};
void vehicle::show()
{
	cout << "车轮数：" << wheels << endl;
	cout << "重量：" << weight << endl;
};
class car :private vehicle //小汽车类
{
	int passenger;//载人数
public:
	car(int wheels1, double weight1, int passenger1);
	void show();
};
car::car(int wheels1, double weight1, int passenger1) :vehicle(wheels1, weight1)
{
	passenger = passenger1;
}
void car::show()
{
	cout << "小车类：" << endl;
	vehicle::show();
	cout << "载人数：" << passenger << endl;
}
class truck :private vehicle //卡车类
{
	int passenger;//载人数
	double payload;//载重量
public:
	truck(int wheels1, double weight1, int passenger1, double payload1);
	void show();
};
truck::truck(int wheels1, double weight1, int passenger1, double payload1) :vehicle(wheels1, weight1)
{
	passenger = passenger1;
	payload = payload1;
}
void truck::show()
{
	cout << "卡车类：" << endl;
	vehicle::show();
	cout << "载人数：" << passenger << endl;
	cout << "载重量：" << payload << endl;
}
int main()
{
	car a(4, 70, 5);
	truck b(6, 380, 3, 300);

	a.show();
	cout << endl<<endl;
	b.show();

	system("PAUSE");
	return 0;
}
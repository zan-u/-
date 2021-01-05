#include <iostream>
#include <math.h>
using namespace std;

class vehicle//建立车辆类
{
protected://保护
	int wheels;
	int weight;
public:
vehicle(int wh, int we)
{
wheels = wh;
weight = we;
}
void display()//显示
{
cout << "wheels=" << wheels << ",weight=" << weight << endl;
}
};
class car:private vehicle//私有派生类
{
int passenger_load;
public:
car(int wh, int we, int p) :vehicle(wh,we)
{
passenger_load = p;
}
void display()
{
vehicle::display();
cout << "passenger_load=" << passenger_load << endl;
}
};
class truck :private vehicle//私有派生类
{
int passenger_load;
int payload;
public:
truck(int wh, int we, int pa,int pay) :vehicle(wh, we)
{
passenger_load = pa;
payload = pay;
}
void display()
{
vehicle::display();
cout << "passenger_load=" << passenger_load << "payload=" << payload << endl;
}
};

void main()//主函数显示数据
{
vehicle v(50, 40);
v.display();


car c(50, 40, 20);
c.display();


truck t(40, 10, 30, 20);
t.display();
 system("pause");
}
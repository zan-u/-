#include <iostream>
#include <math.h>
using namespace std;

class vehicle//����������
{
protected://����
	int wheels;
	int weight;
public:
vehicle(int wh, int we)
{
wheels = wh;
weight = we;
}
void display()//��ʾ
{
cout << "wheels=" << wheels << ",weight=" << weight << endl;
}
};
class car:private vehicle//˽��������
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
class truck :private vehicle//˽��������
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

void main()//��������ʾ����
{
vehicle v(50, 40);
v.display();


car c(50, 40, 20);
c.display();


truck t(40, 10, 30, 20);
t.display();
 system("pause");
}
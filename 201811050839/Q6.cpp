#include <stdio.h>
#include <iostream>
using namespace std;
class vehicle     //����Ķ���
{
protected:      //������Ա����
	int wheels;
	double weight;
public:
	vehicle (int a, double b);    //��ȡ���������ͳ��صĸ�ֵ
	int GetWheels() { return wheels; }   //��ȡ��������
	double GetWeight() { return weight; }    //��ȡ���ӵ�����
	void show();
};
vehicle ::vehicle(int a, double b)
{
	wheels = a;
	weight = b;
};
void vehicle::show()
{
	cout << "��������" << wheels << endl;
	cout << "������" << weight << endl;
};
class car :private vehicle //С������
{
	int passenger;//������
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
	cout << "С���ࣺ" << endl;
	vehicle::show();
	cout << "��������" << passenger << endl;
}
class truck :private vehicle //������
{
	int passenger;//������
	double payload;//������
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
	cout << "�����ࣺ" << endl;
	vehicle::show();
	cout << "��������" << passenger << endl;
	cout << "��������" << payload << endl;
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
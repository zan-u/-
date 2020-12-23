#include<iostream>
using namespace std;

class vehicle
{
public:
	vehicle();
	vehicle(double wh1,double we1);
	void display_wheels();
	void display_weight();
protected:
	double wheels;
	double weight;
};
void vehicle::display_wheels()
{
	cout<<wheels;
}
void vehicle::display_weight()
{
	cout<<weight;
}
vehicle::vehicle(double wh1,double we1)
{
	wheels=wh1;
	weight=we1;
}

//
class car:private vehicle
{
public:
	car();
	car(double pa,double wh2,double we2);
	void display_passenger_load();
private:
	double passenger_load;
	double wheels;
	double weight;
};
void car::display_passenger_load()
{
	cout<<passenger_load;
}
car::car(double pa,double wh2,double we2)
{
	passenger_load=pa;
	wheels=wh2;
	weight=we2;

}
//


class truck:private vehicle
{
public:
	truck();
	truck(double pas,double pay,double wh3,double we3);
	void display_passenger_load();
	void display_payload();
private:
	double passenger_load;
	double payload;
	double wheels;
	double weight;
};
void truck::display_passenger_load()
{
	cout<<passenger_load;
}
void truck::display_payload()
{
	cout<<payload;
}
truck::truck(double pas,double pay,double wh3,double we3)
{
	passenger_load=pas;
	payload=pay;
	wheels=wh3;
	weight=we3;
}




void main()
{
 vehicle v1(40,50);
 car c1(100,15,115);
 truck t1(100,12,12,12);
 v1.display_weight();
 v1.display_wheels();
 c1.display_passenger_load();
 t1.display_passenger_load();
 t1.display_payload();
}
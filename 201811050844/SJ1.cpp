/*
#include<iostream>//a2  b2   a1  b1
#include<fstream>
#include<string>
using namespace std;
int fun(int a,int b)
{
	int c;
	c=a%10*1000+(a/10)*10+b/10+(b%10)*100;
	return c;
}

void main()
{
	int a,b,c;
	cout<<"����a"<<endl;
	cin>>a;
	cout<<"����b"<<endl;
	cin>>b;
	c=fun(a,b);
	cout<<"a��b�ϲ�Ϊc="<<c<<endl;
}
*/



/*
#include<iostream>//a2  b2   a1  b1
#include<fstream>
#include<string>
using namespace std;
void fun(int &c,int &a,int &b)
{
	c=a%10*1000+(a/10)*10+b/10+(b%10)*100;
}

void main()
{
	int a,b,c;
	cout<<"����a"<<endl;
	cin>>a;
	cout<<"����b"<<endl;
	cin>>b;
	fun(c,a,b);
	cout<<"a��b�ϲ�Ϊc="<<c<<endl;
}
*/


#include<iostream>//a2  b2   a1  b1
#include<fstream>
#include<string>
using namespace std;
void fun(int *c,int *a,int *b)
{
	*c=*a%10*1000+(*a/10)*10+*b/10+(*b%10)*100;
}

void main()
{
	int a,b,c;
	cout<<"����a"<<endl;
	cin>>a;
	cout<<"����b"<<endl;
	cin>>b;
	fun(&c,&a,&b);
	cout<<"a��b�ϲ�Ϊc="<<c<<endl;
}
//����ֵ����������
#include<iostream>
using namespace std;
int main()
{
    int fun(int a,int b);
    int a,b,c;
    cout<<"Please enter a,b:"<<endl;
	cin>>a>>b;
    c=fun(a,b);
    cout<<"The number c is:"<<c<<endl;  //���������c
    return 0;
}

int fun(int a,int b)
{
    int c1,c2,c3,c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
    c1=a%10;
    c2=b%10;
    c3=a/10;
    c4=b/10;
    return (c1*1000+c2*100+c3*10+c4);
}
//���ò�������������
#include<iostream>
using namespace std;

void fun(int &a,int &b,int &c)
{
    
	c=(a%10)*1000+(b%10)*100+(a/10)*10+b/10;
 
}
void main()
{
    
    int a,b,c;
    cout<<"Please enter a,b:"<<endl;
	cin>>a>>b;
    fun(a,b,c);
    cout<<"The number c is:"<<c<<endl;  //���������c
    
}
//ָ���������������
#include<iostream>
using namespace std;
void fun(int* a,int* b,int* c);
main()
{
    
    int a,b,c;
    cout<<"Please enter a,b:"<<endl;
	cin>>a>>b;
    fun(&a,&b,&c);
    cout<<"The number c is:"<<c<<endl;  //���������c
   
}
void fun(int* a,int* b,int* c)
{
    int temp=(*a%10)*1000+(*b%10)*100+(*a/10)*10+(*b/10); 
   *c=temp;
}

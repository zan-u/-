#include<stdio.h>
#include<iostream>
using namespace std;

struct node 
{    //结构体定义
int data;   //数据定义
int last;   //前一个结构体编号
int next;   //后一个结构体编号
};

node a[100];   //结构体数组
 
int main()
{
	int n;
	cout<<"输入猴子个数n"<<endl;
	cin>>n;
//	while(scanf("%d",&n)==1)//若成功接收输入数据，则进行循环
		for(int i=2;i<n;i++)
		{
			a[i].data=i; 
			a[i].last=i-1; 
			a[i].next=i+1;
		}
		a[1].data=1; a[1].last=n;   a[1].next=2;   //链表中的数据连成一个圈
		a[n].data=n; a[n].last=n-1; a[n].next=1;
		
		int num=1;       //记录报数次数 
		int count=1;     //记录当前猴子的序号 即第几只猴子
		while(a[count].next!=a[count].data)
		{
			if(num%3==0)     //若该猴子恰好报数为3的整数倍
			{
				a[a[count].last].next=a[count].next;
				a[a[count].next].last=a[count].last;
				
			}
			num++;
			count=a[count].next;
		}
		cout<<"做大王的猴子的编号为"<<endl;
		printf("%d\n",a[count].data);
	
	return 0;
}

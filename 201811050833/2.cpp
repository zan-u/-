//数组
#include<stdio.h>
int main()
{
	int m,n,number,count=1;		//number记猴子剩余个数，count记当前报数
	int monkey[99];
	int t;						//t记数组下标
	int i;
	printf("请输入猴子个数 m 和报数 n ：");
	scanf("%d%d",&m,&n);
	number = m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//t=(t+1)%m实现数组下标加1
			}
			else
			{
				monkey[t]=0;
				count=1;
				number--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			printf("猴子大王：%d\n",monkey[i]);
	}
	return 0;
}
//链表
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
	int m,n;
	cout<<"输入猴子个数m和报数n"<<endl;
	cin>>m>>n;
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
			if(num%n==0)   
			{
				a[a[count].last].next=a[count].next;
				a[a[count].next].last=a[count].last;
				
			}
			num++;
			count=a[count].next;
		}
		cout<<"做大王的猴子的编号为"<<a[count].data<<endl;

	return 0;
}

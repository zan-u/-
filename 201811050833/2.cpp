//����
#include<stdio.h>
int main()
{
	int m,n,number,count=1;		//number�Ǻ���ʣ�������count�ǵ�ǰ����
	int monkey[99];
	int t;						//t�������±�
	int i;
	printf("��������Ӹ��� m �ͱ��� n ��");
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
				t=(t+1)%m;		//t=(t+1)%mʵ�������±��1
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
			printf("���Ӵ�����%d\n",monkey[i]);
	}
	return 0;
}
//����
#include<stdio.h>
#include<iostream>
using namespace std;

struct node 
{    //�ṹ�嶨��
int data;   //���ݶ���
int last;   //ǰһ���ṹ����
int next;   //��һ���ṹ����
};

node a[100];   //�ṹ������
 
int main()
{
	int m,n;
	cout<<"������Ӹ���m�ͱ���n"<<endl;
	cin>>m>>n;
		for(int i=2;i<n;i++)
		{
			a[i].data=i; 
			a[i].last=i-1; 
			a[i].next=i+1;
		}
		a[1].data=1; a[1].last=n;   a[1].next=2;   //�����е���������һ��Ȧ
		a[n].data=n; a[n].last=n-1; a[n].next=1;
		
		int num=1;       //��¼�������� 
		int count=1;     //��¼��ǰ���ӵ���� ���ڼ�ֻ����
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
		cout<<"�������ĺ��ӵı��Ϊ"<<a[count].data<<endl;

	return 0;
}

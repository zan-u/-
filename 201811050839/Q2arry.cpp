#include <iostream.h>
#include <stdio.h>
int main()
{
int m,n,i;   //m
int number;  //numberΪ��������ʣ�µĺ��Ӹ�����
int counter=0;
int monkey[50];
cout<<"������Ӹ���m,�Լ�����n"<<endl;
cin>>m>>n;
number=m;  //��ʼ����ʣ���Ӹ���
for(i=0;i<m;i++)
monkey[i]=i+1; //�����ӱ�ţ�
while(number>1)
{
for(i=0;i<m;i++)
{
if(monkey[i]!=0)
counter++;
if(counter==n)    //�߳�Ȧ�ĺ���
{
monkey[i]=0;
number--;   //Ȧ�ں��Ӹ�����һ ֱ��Ȧ��ֻʣһ������
counter=0;
}
}
}
//counter++;
for(i=0;i<m;i++)
if (monkey[i]!=0)//������ʣ�µ���ֻ���ӣ�����
{
		{
			cout<<"��"<<i+1<<"ֻ����������"<<endl;
			break;
		}
	
}
return 0;
}
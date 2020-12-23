#include <iostream.h>
#include <stdio.h>
int main()
{
int m,n,i;   //m
int number;  //number为数组中所剩下的猴子个数；
int counter=0;
int monkey[50];
cout<<"输入猴子个数m,以及数字n"<<endl;
cin>>m>>n;
number=m;  //初始化所剩猴子个数
for(i=0;i<m;i++)
monkey[i]=i+1; //给猴子编号；
while(number>1)
{
for(i=0;i<m;i++)
{
if(monkey[i]!=0)
counter++;
if(counter==n)    //踢出圈的猴子
{
monkey[i]=0;
number--;   //圈内猴子个数减一 直到圈内只剩一个猴子
counter=0;
}
}
}
//counter++;
for(i=0;i<m;i++)
if (monkey[i]!=0)//输出最后剩下的那只猴子，猴王
{
		{
			cout<<"第"<<i+1<<"只猴子做大王"<<endl;
			break;
		}
	
}
return 0;
}
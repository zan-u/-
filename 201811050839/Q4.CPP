#include<stdio.h>
#include <iostream>
using namespace std;

int main()
{
int m,n;
cout<<"请输入矩形面积的长宽M、N"<<endl;
cin>>m>>n;
char str[][];
int i,j,t;
cout<<"请输入样例"<<endl;
for (i=0;i<n;i++)
for (j=0;j<m;j++)
cin>>str[i][j];
cout<<"请输入感染周期"<<endl;
cin>>t;   //经历的感染周期
//检测区域内是否有感染x
for(k=1;k<=t;k++)
{
  for (i=0;i<n;i++)
  for (j=0;j<m;j++)
  {
    if (str[i][j]==X&&i!=0&&j!=0)
	{
	str[i-1][j]=X;
	str[i][j-1]=X;
	str[i+1][j]=X;
	str[i][j+1]=X;
	}
    else if (str[i][j]==X&&i==0)
	{
	//str[i-1][j]=X;
	str[i][j-1]=X;
	str[i+1][j]=X;
	str[i][j+1]=X;
	}

  }
}
cout<<"输出样例"<<endl;
for(i=0;i<n;i++)
cout<<str[i][]<<endl;
return 0;
}

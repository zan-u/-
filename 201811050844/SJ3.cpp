#include<iostream>
#include<fstream>
using namespace std;
void main()
{	
	struct student
	{
		int yw,sx,yy,no,sum;	
	};
	struct student std[100],st;
	int n,i,j,s,max;
	cout<<"输入参加人数n"<<endl;
	cin>>n;

	for(i=1;i<=n;i++)
	{
		std[i-1].no=i; 
		cin>>std[i-1].yw>>std[i-1].sx>>std[i-1].yy;
		std[i-1].sum=std[i-1].yw+std[i-1].sx+std[i-1].yy;

	}
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i;j<n;j++)
		{	
			if(std[j].sum<std[j+1].sum)max=j+1;
		}
		st=std[i];
		std[i]=std[max];
		std[max]=st;
	}
	
	for(s=0;s<5;s++)
	{
		cout<<std[s].no<<" "<<std[s].sum<<endl;
	}
}

#include<iostream>
#include<fstream>
using namespace std;
void main()
{	
	int i,j,e,d,r,k;
	int n,m,h[100]={0},z[100]={0};
	cin>>n>>m;
	char a[100][100];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>d;
	for(r=0;r<d;r++)
	{
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='X')
			{
				h[k]=i;
				z[k++]=j;
			}
		}
	}

	for(e=0;e<k;e++)
	{
		if(a[h[e]+1][z[e]]!='P')a[h[e]+1][z[e]]='X';
		if(a[h[e]-1][z[e]]!='P')a[h[e]-1][z[e]]='X';
		if(a[h[e]][z[e]+1]!='P')a[h[e]][z[e]+1]='X';
		if(a[h[e]][z[e]-1]!='P')a[h[e]][z[e]-1]='X';
	}
	}
//

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
}



#include <iostream>
using namespace std;

main()
{   int M,N,c;
    cin>>N>>M;//�����ͼ���Ϳ�
	char a[100][100];
	for(int m=0;m<M;m++)
	{
		for(int n=0;n<N;n++)
        cin>>a[m][n];//����M������״̬
    }
	cin>>c;//��������
	for(int h=0;h<c;h++)
    {
		for(int i=0;i<M;i++)
		{
		for(int j=0;j<N;j++)
		{
			if(a[i][j]=='X')//�жϸ�Ⱦ����Χ�Ƿ������������ͬʱ�ж��Ƿ��Ǳ�����
			{
				if(i-1>=0&&a[i-1][j]!='P')
					a[i-1][j]='Y';
				if(i+1<M&&a[i+1][j]!='P')
					a[i+1][j]='Y';
				if(j-1>=0&&a[i][j-1]!='P')
					a[i][j-1]='Y';
				if(j+1<N&&a[i][j+1]!='P')
					a[i][j+1]='Y';
			}
		}
		}
		for(int q=0;q<M;q++)
		{
		for(int p=0;p<N;p++)
		{
			if(a[q][p]=='Y')
				a[q][p]='X';
		}
		}

	}
	for(int l=0;l<M;l++)
	{
		for(int k=0;k<N;k++)
        cout<<a[l][k];
		cout<<endl;
    }

}
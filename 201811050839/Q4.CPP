#include<stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cout << "请输入矩形面积的长宽M、N" << endl;
	cin >> m >> n;
	char str[20][10];
	int i, j, t, k;
	cout << "请输入样例" << endl;
	for (i = 0; i < n; i++)
		//for (j=0;j<m;j++)
	{
		cout << "输入" << endl;
		cin >> str[i];
	}
	cout << str[1][1];
	//for (i = 0; i < n; i++)
	//{
	//	//for (j = 0; j < m; i++)
	//		cout << str[i];
	//}
	//cout<<str;
	cout << "请输入感染周期" << endl;
	cin >> t;   //经历的感染周期
	//检测区域内是否有感染x
	for (k = 1; k <= t; k++)
	{
		for (i = 1; i < n - 1; i++)
		{
			if (str[i][0] == 'X')
			{
				if (str[i - 1][0] != 'P')
					str[i - 1][0] = 'W';
				if (str[i + 1][0] != 'P')
					str[i + 1][0] = 'W';
				if (str[i][1] != 'P')
					str[i][1] = 'W';
			}
			if (str[i][m - 1] == 'X')
			{
				if (str[i - 1][m - 1] != 'P')
					str[i - 1][m - 1] = 'W';
				if (str[i + 1][m - 1] != 'P')
					str[i + 1][m - 1] = 'W';
				if (str[i][m - 2] != 'P')
					str[i][m - 2] = 'W';
			}
			for (j = 1; j < m - 1; j++)
			{
				if (str[n - 1][j] == 'X'&&i == 1)
				{
					if (str[n - 1][j - 1] != 'P')
						str[n - 1][j - 1] = 'W';
					if (str[n - 1][j + 1] != 'P')
						str[n - 1][j + 1] = 'W';
					if (str[n - 2][j] != 'P')
						str[n - 2][j] = 'W';
				}
				if (str[i - 1][j] == 'X'&&i == 1)
				{
					if (str[0][j - 1] != 'P')
						str[0][j - 1] = 'W';
					if (str[0][j + 1] != 'P')
						str[0][j + 1] = 'W';
					if (str[1][j] != 'P')
						str[1][j] = 'W';
				}
				if (str[i][j] == 'X')
				{
					if (str[i - 1][j] != 'P')
						str[i - 1][j] = 'W';
					if (str[i][j - 1] != 'P')
						str[i][j - 1] = 'W';
					if (str[i + 1][j] != 'P')
						str[i + 1][j] = 'W';
					if (str[i][j + 1] != 'P')
						str[i][j + 1] = 'W';
				}				
			}
		}
		for ( i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				if (str[i][j] == 'W')
					str[i][j] = 'X';
		}
	}
	cout << "输出样例" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << str[i][j];
		}
		cout << endl;
	}
	return 0;
}
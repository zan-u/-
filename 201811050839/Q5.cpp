#include <stdio.h>
#include <iostream>
#define MAX  100   //ȫ�ֱ�������
using namespace std;
int level(char n)  //�涨��������ȵȼ�
{
	int temp;
	switch (n)
	{
	case '*':
	case '/':temp = 3; break;
	case '+':
	case '-':temp = 2; break;
	case '(':temp = 1; break;
	case '@':temp = -1; break;
	}
	return temp;
}

void  cal(int number[], int* numberTop, char Symbol[], int* SymbolTop) //���ַ�ջ��ȡ��һ���ַ�������ֵջ��ȡ��������ֵ��������
{
	char operation = Symbol[(*SymbolTop)]; //�ӷ���ջ��ȡ������
	(*SymbolTop)--;
	int value1 = number[(*numberTop)];
	(*numberTop)--;
	int value2 = number[(*numberTop)];  //������ջ��ȡֵ
	(*numberTop)--;
	int temp;
	switch (operation)
	{
	case '+':temp = value2 + value1; break;
	case '-':temp = value2 - value1; break;
	case '*':temp = value2 * value1; break;
	case '/':temp = value2 / value1; break;
	}
	(*numberTop)++;     //��������������������ţ�����������
	number[*numberTop] = temp;    //�����Ľ������ջ��
}
int fun(char str[])
{
	char  Symbol[MAX];
	int SymbolTop = -1;  //�����ջ
	int numberTop = -1;  //��ֵջ
	int  number[MAX];
	int  y = 0; //���������λ�� 
	int i = 0;
	Symbol[++SymbolTop] = '@'; //�Ȱ� @ ���뵽����ջ��,�Ͳ����ж�ջ�Ƿ����
	while (str[i])
	{  //�ȱ������ַ���
		y = 0;
		if (str[i] <= '9' && str[i] >= '0')
		{ //������
			while (str[i] <= '9' && str[i] >= '0')
			{
				y = y * 10 + str[i] - '0';
				i++;
			}
			number[++numberTop] = y; //��ջ��ֵ
		}
		else if ((str[i] > '9' || str[i] < '0') && str[i] != '(' && str[i] != ')') 
		{   //��������,�ų���,�����ŵ����
			while (level(str[i]) <= level(Symbol[SymbolTop]))  //��ջ�б�����ĺ͵������Ķ���ջ��������׺���ʽת��׺���ʽ�ĺ���
															//�ӷ���ջ�г�һ�����ţ�����ֵջ�г��������֣������ѹ����ֵջ
				cal(number, &numberTop, Symbol, &SymbolTop);
			Symbol[++SymbolTop] = str[i];
			i++;
		}
		else if (str[i] == '(') {   //����������ֱ����ջ
			Symbol[++SymbolTop] = '(';
			i++;
		}
		else if (str[i] == ')') 
		{   //��������ֱ������������
			while (Symbol[SymbolTop] != '(')
			{
				cal(number, &numberTop, Symbol, &SymbolTop);
			}
			SymbolTop--; //�������Ÿ��ǵ�
			i++;
		}
		// ��Symbol ջ���һ�£�����number ��ջ��������
	}
	while (Symbol[SymbolTop] != '@')
	{
		cal(number, &numberTop, Symbol, &SymbolTop);
	}
	return number[numberTop];
}
int main(void)
{
	char str[MAX];
	int result;
	cout << "������Ҫ������ַ���" << endl;
	cin>>str;
	result = fun(str);
	cout << "������Ϊ" << endl;
	cout << result << endl;
	return 0;
}
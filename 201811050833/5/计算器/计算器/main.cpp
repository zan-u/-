#include <iostream>
#include "mystack.cpp"
#include "cal.h"
using namespace std;
int main()
{
	Calculator calc1;//创建计算器对象
	do
	{
		calc1.clear();
		cout << "Please input an expression, ended with a '#'" << endl;
		calc1.evaluate();//计算表达式并显示结果
		cout << endl << "Would you like to continue? [y/n]" << endl;
		fflush(stdin);
	} while (cin.get() == 'y');

	return 0;
}
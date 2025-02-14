#include <iostream>
#include "mystack.cpp"
#include "cal.h"
#include <ctype.h>//调用了isdigit和isalpha函数
using namespace std;
void Calculator::evaluate()//利用栈结构将键盘输入的中缀表达式转为RPN计算，并检查输入的正确性
{
	char ch, op, theta;//当前读入字符、操作符、运算符
	double val, a, b;//数值、左操作数、右操作数
	cin >> ch;
	op = '#';
	bool is_matched = true;//标记左右括号是否匹配
	do
	{
		while (isalpha(ch)) { cin >> ch; }//过滤非法字符输入（英文字母）
		is_matched = true;

		switch (ch)//左右括号匹配检查
		{
		case '(': bracket.push(ch); break;//左括号入栈
		case ')': if (bracket.empty())
			//右括号没有已入栈的左括号来匹配时，输入非法
			is_matched = false;
				  else
		{
			bracket.pop();  is_matched = true;
		}//匹配时，弹出一个左括号
				  break;
		default: break;//非括号的字符一律过滤掉
		}
		while (is_matched)//右括号匹配时，执行中缀表达式运算
		{
			if (isdigit(ch))//当前字符为数字时，将它放入操作数栈
			{//isdigit遇到多位数会自动识别吗？
				cin.putback(ch);//答：当然不能。因为isdigt的参数是char型的，它只能判断一位字符
				cin >> val;//这也是为什么要cin.putback(ch)再cin>>out了。cin的功能很强大，自动匹配数据类型，而不用scanf的各种格式化输入符
				opnd.push(val);
				cin >> ch; break;
			}
			else if (lp(op) < rp(ch))
			{//当前操作符优先级高于栈顶操作符时，入栈
				optr.push(ch);
				op = optr.top();
				cin >> ch; break;
			}
			else if (lp(op) == rp(ch))
			{//当前操作符优先级等于栈顶操作符时，当前栈顶操作符出栈
				optr.pop();
				op = optr.top();
				cin >> ch; break;
			}
			else if (lp(op) > rp(ch))
			{//当前操作符优先级低于栈顶，将栈顶取出进行运算，再将结果放回操作数栈
				theta = op;  optr.pop();
				b = opnd.top();  opnd.pop();
				a = opnd.top();  opnd.pop();//注意两个操作数的出栈顺序
				opnd.push(operate(theta, a, b));
				op = optr.top();
				if ((ch == ')') && (op == '('))//解决左右括号匹配后的问题
				{
					optr.pop();  op = optr.top();//左括号出栈
					cin >> ch;//刷新当前字符（避免对右括号二次判断）
					if (ch == '(') is_matched = false;//右括号紧邻左括号，报错
				}
				break;
			}
		}
		if (is_matched == false || (op == '(' && ch == '#'))
		{//最后还剩没配上对的左括号，或者右括号没有左括号来匹配，则输入非法
			cout << "错误输入" << endl;
			ch = op = '#';
			is_matched = false;
		}
	} while (ch != '#' || op != '#');

	if (is_matched == true) cout << '=' << opnd.top();//循环结束后，结果在操作数栈顶
	else {
		cout << "sorry, cannot compute this expression." << endl;
	}
}
int Calculator::lp(char op)//返回左端操作符的优先级
{
	int prior;//优先级
	switch (op)
	{
	case '+'://将优先级表的内容写入
	case '-': prior = 3; break;
	case '*':
	case '/': prior = 5; break;
	case '(': prior = 1; break;
	case ')': prior = 6; break;
	case '#': prior = 0; break;
	}
	return prior;
}
int Calculator::rp(char op)//返回右端操作符的优先级
{
	int prior;//优先级
	switch (op)
	{
	case '+':
	case '-': prior = 2; break;
	case '*':
	case '/': prior = 4; break;
	case '(': prior = 6; break;
	case ')': prior = 1; break;
	case '#': prior = 0; break;
	}
	return prior;
}
double Calculator::operate(char theta, double a, double b)
//进行后缀表达式的运算，返回运算结果
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: return 0;
	}
}
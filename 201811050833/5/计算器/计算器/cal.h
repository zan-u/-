#pragma once
using namespace std;
class Calculator
{
private://私有成员（数据成员）
	MyStack<char> optr;//操作符栈
	MyStack<double> opnd;//操作数栈
	MyStack<char> bracket;//用于存放左括号的栈
public://公有成员（供外界调用的成员函数，即方法）
	Calculator()//构造函数
	{
		optr.setnull();//操作符清空
		opnd.setnull();//操作数栈清空
		bracket.setnull();//左括号栈清空
		optr.push('#');//‘#’作为栈底哨兵
	}
	void evaluate();//利用栈结构将中缀表达式转为PRN来计算，并检查输入的合法性
	void clear()//清空计算器
	{
		optr.setnull();
		optr.setnull();
		bracket.setnull();
		optr.push('#');//与构造的实现是一致的
	}

private://私有成员（对外隐藏的成员函数，只供内部调用）
	int lp(char op);//返回左端操作符的优先级
	int rp(char op);//返回右端操作符的优先级
	double operate(char theta, double a, double b);//进行后缀表达式的运算，返回运算结果
};
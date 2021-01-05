#include <iostream>
#include "mystack.h"
using namespace std;
template <class Stack_entry>
MyStack<Stack_entry>::MyStack()
/*Pre���ա�
  POST����ջ����ʼ��Ϊ�ա�*/
{
	count = 0;
}
template <class Stack_entry>
bool MyStack<Stack_entry>::empty() const
/*Pre���ա�
POST�������ջΪ�գ��򷵻�TRUE�����򷵻�False��*/
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry &item)
/*Pre���ա�
POST�������ջδ��������Ŀ��ӵ���ջ���������򣬷������������룬��ջ���ֲ��䡣*/
{
	Error_code outcome = success;
	if (count >= maxstack) outcome = overflow;
	else entry[count++] = item;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
/*Pre���ա�
POST�������ջ��Ϊ�գ����Ƴ���ջ�Ķ����������ջΪ�գ��򷵻����������롣*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else --count;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item) const
/*Pre���ա�
POST�������ջ��Ϊ�գ�����Item�з��ض�ջ�Ķ����������ջΪ�գ��򷵻����������롣*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else item = entry[count - 1];
	return outcome;
}
template <class Stack_entry>
Stack_entry MyStack<Stack_entry>::top()const//����top��������Ӧ��ͬ����Ҫ
{
	if (count == 0) underflow;
	return entry[count - 1];
}
template <class Stack_entry>
void MyStack<Stack_entry>::setnull()
{
	count = 0;//�빹��ʵ����һ�µ�
}

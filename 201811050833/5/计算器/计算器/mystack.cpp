#include <iostream>
#include "mystack.h"
using namespace std;
template <class Stack_entry>
MyStack<Stack_entry>::MyStack()
/*Pre：空。
  POST：堆栈被初始化为空。*/
{
	count = 0;
}
template <class Stack_entry>
bool MyStack<Stack_entry>::empty() const
/*Pre：空。
POST：如果堆栈为空，则返回TRUE。否则返回False。*/
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry &item)
/*Pre：空。
POST：如果堆栈未满，则将项目添加到堆栈顶部。否则，返回溢出错误代码，堆栈保持不变。*/
{
	Error_code outcome = success;
	if (count >= maxstack) outcome = overflow;
	else entry[count++] = item;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
/*Pre：空。
POST：如果堆栈不为空，则移除堆栈的顶部。如果堆栈为空，则返回下溢错误代码。*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else --count;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item) const
/*Pre：空。
POST：如果堆栈不为空，则在Item中返回堆栈的顶部。如果堆栈为空，则返回下溢错误代码。*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else item = entry[count - 1];
	return outcome;
}
template <class Stack_entry>
Stack_entry MyStack<Stack_entry>::top()const//重载top函数以适应不同的需要
{
	if (count == 0) underflow;
	return entry[count - 1];
}
template <class Stack_entry>
void MyStack<Stack_entry>::setnull()
{
	count = 0;//与构造实现是一致的
}

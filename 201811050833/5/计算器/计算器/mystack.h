#pragma once
const int maxstack = 10;//栈内元素个数的最大值
enum Error_code { success, underflow, overflow };//函数运行成功与否的内部标签
template <class Stack_entry>//类模板
class MyStack
{
public:                    //共有成员
	MyStack();
	bool empty() const;
	Error_code push(const Stack_entry &item);
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Stack_entry top()const;        //重载top函数以适应不同的需要
	void setnull();//清空栈
private:                //私有成员（数据成员）
	int count;        //计数器
	Stack_entry entry[maxstack];//用数组实现存储
};
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//  栈stack   先进后出，  在栈顶添加，栈顶删除，中间不允许操作
//  队列queue 先进先出，  在队尾添加，队头删除，中间不允许操作
int main()
{
	//stack<int> sk;
	//sk.push(1);
	//sk.push(2);
	//sk.push(3);
	//sk.push(4);
	//while (sk.empty() == false)
	//{
	//	cout<<sk.top()<<" ";
	//	sk.pop();
	//}

	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	while (qu.empty() == false)
	{
		cout<<qu.front()<<" ";
		qu.pop();
	}

	system("pause");
	return 0;
}
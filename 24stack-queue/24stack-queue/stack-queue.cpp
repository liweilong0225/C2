#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//  ջstack   �Ƚ������  ��ջ����ӣ�ջ��ɾ�����м䲻�������
//  ����queue �Ƚ��ȳ���  �ڶ�β��ӣ���ͷɾ�����м䲻�������
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
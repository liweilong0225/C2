#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
	vector<list<int>> vec(7);//创建7个链表
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			vec[i].push_back(j+1);
		}
	}

	for (int i = 0; i < 7; i++)//打印出阶梯链表
	{
		list<int>::iterator ite = vec[i].begin();
		while (ite != vec[i].end())
		{
			cout<<*ite<<" ";
			++ite;
		}
		cout<<endl; 
	}

	//==========================================
	list<vector<int>> lst;//创建一个容器数组
	list<vector<int>>::iterator ite = lst.begin();
	while (ite != lst.end())
	{
		vector<int>::iterator itevec = (*ite).begin();
		while (itevec != (*ite).end())
		{
			cout << *itevec <<" ";
			++itevec;
		}
		++ite;
	}
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

void Show(int a)
{
	cout<< a << " ";
}
bool Rule1(int a,int b)
{
	return a>b;
}
bool Rule2(int a,int b)
{
	return a<b;
}
int main()
{
	srand((unsigned int)time(0));
	vector<int> vec(10);
	for (int i = 0; i < 10; i++)
	{
		vec[i] = i;
	}
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::random_shuffle(vec.begin(),vec.end());//随机排序
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::sort(vec.begin(),vec.end(),&Rule1);	//降序排序
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::sort(vec.begin(),vec.end(),&Rule2);	//升序排序
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::reverse(vec.begin(),vec.end());		//翻转
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	cout<<::count(vec.begin(),vec.end(),1)<<endl;//统计1出现的次数（可改）

	system("pause");
	return 0;
}
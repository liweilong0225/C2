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

	::random_shuffle(vec.begin(),vec.end());//�������
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::sort(vec.begin(),vec.end(),&Rule1);	//��������
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::sort(vec.begin(),vec.end(),&Rule2);	//��������
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	::reverse(vec.begin(),vec.end());		//��ת
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl;

	cout<<::count(vec.begin(),vec.end(),1)<<endl;//ͳ��1���ֵĴ������ɸģ�

	system("pause");
	return 0;
}
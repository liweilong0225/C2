#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Show(int a)
{
	cout<< a <<" ";
}
int main()
{
	vector<int> vec(10);

	//vector<int>::iterator ite = vec.begin();
	//while (ite!= vec.end())
	//{
	//	cout<<*ite<<" ";
	//	++ite;
	//}
	//cout<<endl<<"====================="<<endl;

	//for (int i = 0; i < 10; i++)
	//{
	//	cout<<vec[i]<<" ";
	//}
	//cout<<endl<<"====================="<<endl;

	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl<<"====================="<<endl;
	cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	vec.push_back(5);						//新空间是原来空间的1.5倍
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl<<"====================="<<endl;
	cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	//vec.pop_back();							//删除
	//::for_each(vec.begin(),vec.end(),&Show);
	//cout<<endl<<"====================="<<endl;
	//cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	vector<int>::iterator itePos = ::find(vec.begin(),vec.end(),5);
	vec.insert(itePos,100);						//指定位置插入
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl<<"====================="<<endl;
	cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	itePos = ::find(vec.begin(),vec.end(),100);
	vec.erase(itePos);							//指定位置删除
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl<<"====================="<<endl;
	cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	
	vec.clear();								//清空
	::for_each(vec.begin(),vec.end(),&Show);
	cout<<endl<<"====================="<<endl;
	cout<<"size:"<<vec.size()<<"	"<<"capacity:"<<vec.capacity()<<endl;

	system("pause");
	return 0;
}
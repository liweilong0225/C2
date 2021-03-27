#include<iostream>
#include<list>
#include<algorithm>
#include<time.h>
using namespace std;

void Show(int a)
{
	cout<< a << " ";
}
int main()
{
	list<int> lst1;
	lst1.push_back(3);
	lst1.push_back(3);
	lst1.push_back(1);
	lst1.push_back(1);
	lst1.push_back(1);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(2);
	lst1.push_back(3);

	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	//lst1.remove(3);	//把所有的3删除
	lst1.unique();		//删除连续相同的
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	list<int> lst2;
	lst2.push_back(4);
	lst2.push_back(6);
	lst2.push_back(9);
	lst2.push_back(0);
	lst2.push_back(1);
	lst2.push_back(5);
	lst2.push_back(2);

	list<int>::iterator itePos = ::find(lst1.begin(),lst1.end(),1);
	list<int>::iterator iteFirst = ::find(lst2.begin(),lst2.end(),6);
	list<int>::iterator iteLast = ::find(lst2.begin(),lst2.end(),5);

	//lst1.splice(itePos,lst2);//在lst1这个链表的itePos位置，插入lst2整个链表
	//lst1.splice(itePos,lst2,iteFirst);//在lst1这个链表的itePos位置，插入lst2这个链表的itePos标记的一个元素
	lst1.splice(itePos,lst2,iteFirst,iteLast);//在lst1这个链表的itePos位置，插入lst2这个链表的从iteFirst到iteLast这一段
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.sort();//从到到小排序
	lst2.sort();
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.merge(lst2);//将两个有序链表合并
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.reverse();//翻转
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	system("pause");
	return 0;
}
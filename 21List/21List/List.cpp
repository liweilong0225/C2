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

	//lst1.remove(3);	//�����е�3ɾ��
	lst1.unique();		//ɾ��������ͬ��
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

	//lst1.splice(itePos,lst2);//��lst1��������itePosλ�ã�����lst2��������
	//lst1.splice(itePos,lst2,iteFirst);//��lst1��������itePosλ�ã�����lst2��������itePos��ǵ�һ��Ԫ��
	lst1.splice(itePos,lst2,iteFirst,iteLast);//��lst1��������itePosλ�ã�����lst2�������Ĵ�iteFirst��iteLast��һ��
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.sort();//�ӵ���С����
	lst2.sort();
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.merge(lst2);//��������������ϲ�
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;
	::for_each(lst2.begin(),lst2.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	lst1.reverse();//��ת
	::for_each(lst1.begin(),lst1.end(),&Show);
	cout<<endl;
	cout<<"==============================="<<endl;

	system("pause");
	return 0;
}
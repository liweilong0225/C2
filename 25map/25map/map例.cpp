#include<iostream>
#include<map>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	//map<string,int> mp;
	//mp["����ѧ"] = 104;
	//mp["�ڴ�"] = 106;
	//mp["��װ��"] = 114;
	//string  str;
	//cin>>str;
	//cout<<mp[str]<<endl;

	map<string,list<int>> mp;
	mp["����ѧ"].push_back(1);
	mp["����ѧ"].push_back(2);
	mp["����ѧ"].push_back(3);
	mp["����ѧ"].push_back(4);

	mp["�ڴ�"].push_back(11);
	mp["�ڴ�"].push_back(22);
	mp["�ڴ�"].push_back(33);
	mp["�ڴ�"].push_back(44);

	mp["��װ��"].push_back(111);
	mp["��װ��"].push_back(222);
	mp["��װ��"].push_back(333);
	mp["��װ��"].push_back(444);

	string str;
	cin >> str;
	list<int>::iterator ite = mp[str].begin();
	while (ite != mp[str].end())
	{
		cout<<*ite<<" ";
		++ite;
	}

	system("pause");
	return 0;
}
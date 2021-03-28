#include<iostream>
#include<map>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	//map<string,int> mp;
	//mp["理工大学"] = 104;
	//mp["黑大"] = 106;
	//mp["服装城"] = 114;
	//string  str;
	//cin>>str;
	//cout<<mp[str]<<endl;

	map<string,list<int>> mp;
	mp["理工大学"].push_back(1);
	mp["理工大学"].push_back(2);
	mp["理工大学"].push_back(3);
	mp["理工大学"].push_back(4);

	mp["黑大"].push_back(11);
	mp["黑大"].push_back(22);
	mp["黑大"].push_back(33);
	mp["黑大"].push_back(44);

	mp["服装城"].push_back(111);
	mp["服装城"].push_back(222);
	mp["服装城"].push_back(333);
	mp["服装城"].push_back(444);

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
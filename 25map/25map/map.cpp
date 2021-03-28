//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//void Show(pair<char,int> pr)
//{
//	cout<<pr.first<<" "<<pr.second<<endl;
//}
//
//int main()
//{
//	map<char,int> mp;
//	mp['D'] = 100;
//	mp['F'] = 200;
//	mp['A'] = 300;
//	mp['C'] = 400;
//	mp['E'] = 500;
//	mp['B'] = 600;
//
//	//map<char,int>::iterator ite = mp.begin();
//	//while (ite!=mp.end())
//	//{
//	//	cout<<ite->first<<" "<<ite->second<<endl;
//	//	++ite;
//	//}
//	//cout<<"==================================="<<endl;
//
//	::for_each(mp.begin(),mp.end(),&Show);
//	cout<<"==================================="<<endl;
//
//	map<char,int>::iterator ite = mp.begin();
//	//ite->first = 'k';//键值不能修改
//	ite->second = 123;
//	mp['B'] = 456;
//	::for_each(mp.begin(),mp.end(),&Show);
//	cout<<"==================================="<<endl;
//
//	map<char,int>::iterator itePos = mp.find('C');
//	mp.erase(itePos);//删除
//	::for_each(mp.begin(),mp.end(),&Show);
//	cout<<"==================================="<<endl;
//
//	pair<char,int> pr('C',567);//插入
//	mp.insert(pr);
//	::for_each(mp.begin(),mp.end(),&Show);
//	cout<<"==================================="<<endl;
//
//	cout<<mp.count('C')<<endl;//判断键值是否存在
//
//	itePos = mp.lower_bound('A');//返回该键值或者大于该键值的map的迭代器
//	cout<<itePos->first<<" "<<itePos->second<<endl;
//
//	itePos = mp.upper_bound('A');//返回大于该键值的map的下一个的迭代器
//	cout<<itePos->first<<" "<<itePos->second<<endl;
//
//	system("pause");
//	return 0;
//}
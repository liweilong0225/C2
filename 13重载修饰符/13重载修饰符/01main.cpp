#include<iostream>
#include"Num.h"
using namespace std;

int operator+(int num,CNum& n)
{
	return num+n.m_nNum;
}

ostream& operator<<(ostream& os,CNum& num)
{
	os<<num.m_nNum;
	return os;
}
istream& operator>>(istream& is,CNum& num)
{
	is>>num.m_nNum;
	return is;
}
int main()
{
	//CNum aa;
	//aa = 100;
	//cout<<aa.m_nNum<<endl;

	//CNum bb;
	//bb = aa + 100;
	//cout<<bb.m_nNum<<endl;

	//CNum cc;
	//cc = 200 + aa;
	//cout<<cc.m_nNum<<endl;

	//cout<<aa<<endl;
	//cin>>aa;
	//cout<<aa<<endl;

	CNum dd;
	cout<<dd++<<endl;
	cout<<dd++<<endl;

	system("pause");
	return 0;
}
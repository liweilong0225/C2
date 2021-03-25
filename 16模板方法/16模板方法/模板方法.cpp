#include<iostream>
using namespace std;

class CPerson
{
public:
	virtual void EatStyle() = 0;
public:
	void Eat()
	{
		cout<<"来一碗饭"<<endl;
		this->EatStyle();
		cout<<"放嘴里"<<endl;
		cout<<"咀嚼几下"<<endl;
		cout<<"咽下去"<<endl;
	}
};
class CChina : public CPerson
{
public:
	void EatStyle()
	{
		cout<<"用筷子夹"<<endl;
	}
};
class CUSA: public CPerson
{
public:
	void EatStyle()
	{
		cout<<"用刀叉"<<endl;
	}
};
class CIndia : public CPerson
{
	public:
	void EatStyle()
	{
		cout<<"用手抓"<<endl;
	}
};
int main()
{
	CChina cn;
	cn.Eat();
	cout<<"===================="<<endl;
	CUSA us;
	us.Eat();
	cout<<"===================="<<endl;
	CIndia in;
	in.Eat();
	system("pause");
	return 0;
}
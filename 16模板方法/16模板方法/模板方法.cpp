#include<iostream>
using namespace std;

class CPerson
{
public:
	virtual void EatStyle() = 0;
public:
	void Eat()
	{
		cout<<"��һ�뷹"<<endl;
		this->EatStyle();
		cout<<"������"<<endl;
		cout<<"�׽�����"<<endl;
		cout<<"����ȥ"<<endl;
	}
};
class CChina : public CPerson
{
public:
	void EatStyle()
	{
		cout<<"�ÿ��Ӽ�"<<endl;
	}
};
class CUSA: public CPerson
{
public:
	void EatStyle()
	{
		cout<<"�õ���"<<endl;
	}
};
class CIndia : public CPerson
{
	public:
	void EatStyle()
	{
		cout<<"����ץ"<<endl;
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
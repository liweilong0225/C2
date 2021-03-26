#include<iostream>
using namespace std;

template<typename TT,typename KK>
class MyClass
{
public:
	TT m_t;
	KK m_k;
public:
	MyClass(TT t,KK k)
	{
		m_t = t;
		m_k = k;
	}
public:
	void Show()
	{
		cout<<m_t<<endl<<m_k<<endl;
	}
};

template <typename TT>
class CPerson
{
public:
	TT m_t;
public:
	CPerson(TT t)
	{
		m_t = t;
	}
};

template <typename KK>
class CAnimal
{
public:
	KK m_k;
public:
	CAnimal()
	{
		m_k = 0;
	}
};


int main()
{
	MyClass<int,double> ps1(1,0.12);
	ps1.Show();
	cout<<"=========================="<<endl;
	CAnimal<int> an;
	CPerson<CAnimal<int>> ps(an);
	system("pause");
	return 0;
}
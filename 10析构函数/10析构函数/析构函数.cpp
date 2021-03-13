#include<iostream>
using namespace std;
#include<windows.h>

class CPerson
{
private:
	char* m_nName;
public:
	CPerson()
	{
		m_nName = new char[10];
		strcpy_s(m_nName,10,"abcdefgh");
	}
	~CPerson()
	{
		delete[] m_nName;
		m_nName = 0;
		cout<<"~CPerson"<<endl;
	}
public:
	void Show()
	{
		cout<<m_nName<<endl;
	}
};
int main()
{
	{
		CPerson ps;
		ps.Show();
	}
	//析构函数在对象什么周期结束时调用
	system("pause");
	return 0;
}
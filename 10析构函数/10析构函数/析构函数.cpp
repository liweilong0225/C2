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
	//���������ڶ���ʲô���ڽ���ʱ����
	system("pause");
	return 0;
}
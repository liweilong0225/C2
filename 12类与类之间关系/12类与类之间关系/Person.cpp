#include "Person.h"
#include<iostream>
using namespace std;

CPerson::CPerson(void)
{
	m_pFirend = 0;
}


CPerson::~CPerson(void)
{
}
void CPerson::Do()
{
	Head.Say();
	Hand.Move();
}
void CPerson::Coding(CComputer& cp)
{
	cout<<"�ü���"<<endl;
	cp.Code();
}
void CPerson::FindFirend(CFriend* pFriend)
{
	if(pFriend->rp > 5)
		m_pFirend = pFriend;
}
void CPerson::LOL()
{
	if (m_pFirend == 0)
	{
		cout<<"��һ����"<<endl;
		cout<<"�Լ���"<<endl;
	}
	else
	{
		cout<<"��������"<<endl;
		m_pFirend->Play();
	}
}
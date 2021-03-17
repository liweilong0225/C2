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
	cout<<"敲键盘"<<endl;
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
		cout<<"抽一根烟"<<endl;
		cout<<"自己玩"<<endl;
	}
	else
	{
		cout<<"抽两根烟"<<endl;
		m_pFirend->Play();
	}
}
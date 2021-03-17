#pragma once
#include"Head.h"
#include"Hand.h"
#include"Friend.h"
#include"Computer.h"
class CPerson
{
private:
	CHead Head;
	CHand Hand;
	CFriend* m_pFirend;
public:
	CPerson(void);
	~CPerson(void);
public:
	void Do();
	void Coding(CComputer& cp);
	void FindFirend(CFriend* pFriend);
	void LOL();
};


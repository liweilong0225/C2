#pragma once
#include<list>
#include"Cage.h"
using namespace std;

class CHouse
{
public:
	list<CCage*> m_lstCage;
public:
	CHouse(void);
	~CHouse(void);
};


#pragma once
#include"House.h"
class CAnne
{
public:
	CAnne(void);
	~CAnne(void);
public:
	void AndAnimalPlay(CHouse& house,int nID);
	void LookLook(CHouse& house);
	bool PushAnimel(CHouse& house,int nID,CAnimal* pAnimal);
	void PushCage(CHouse& house,int nCount);
};


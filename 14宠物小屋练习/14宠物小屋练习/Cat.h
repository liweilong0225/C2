#pragma once
#include "animal.h"
class CCat :
	public CAnimal
{
public:
	CCat(void);
	~CCat(void);
public:
	virtual void Play();
};


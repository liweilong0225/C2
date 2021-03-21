#pragma once
#include "animal.h"
class CDog :
	public CAnimal
{
public:
	CDog(void);
	~CDog(void);
public:
	virtual void Play();
};


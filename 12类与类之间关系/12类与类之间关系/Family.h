#pragma once
#include"Person.h"
class CFamily
{
public:
	CPerson* arr[10];
public:
	CFamily(void);
	~CFamily(void);
public:
	void PushPerson(CPerson* ps);
	void AllPersonCoding(CComputer& cp);
};


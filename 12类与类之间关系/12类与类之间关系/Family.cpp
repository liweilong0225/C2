#include "Family.h"
#include<iostream>
#include<Windows.h>
using namespace std;

CFamily::CFamily(void)
{
	//for (int i = 0; i < 10; i++)
	//	arr[i] = 0;
	ZeroMemory(arr,4*10);
}


CFamily::~CFamily(void)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != 0)
		{
			delete arr[i];
			arr[i] = 0;
		}
	}
}
void CFamily::PushPerson(CPerson* ps)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = ps;
			return;
		}
	}
}
void CFamily::AllPersonCoding(CComputer& cp)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 0)
		{
			cout<<"----------NULL-----------"<<endl;
		}
		else
		{
			arr[i]->Coding(cp);
		}
	}
}
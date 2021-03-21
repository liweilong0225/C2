#include "Animal.h"
#include<iostream>
using namespace std;

CAnimal::CAnimal(void)
{
	m_strName = "";
	m_strColor = "";
	m_strSex = "";
}


CAnimal::~CAnimal(void)
{
}
void CAnimal::Init(string strName,string strColor,string strSex)
{
	m_strName = strName;
	m_strColor = strColor;
	m_strSex = strSex;
}
void CAnimal::Show()
{
	cout <<"Name:" << m_strName << " Color:" << m_strColor <<" Sex:"<< m_strSex << endl;
}
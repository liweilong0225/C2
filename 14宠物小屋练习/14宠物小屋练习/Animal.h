#pragma once
#include<iostream>
#include<string>
using namespace std;

class CAnimal
{
public:
	CAnimal(void);
	virtual ~CAnimal(void);
public:
	string m_strName;
	string m_strColor;
	string m_strSex;
public:
	virtual void Play() = 0;
public:
	void Init(string strName,string strColor,string strSex);
	void Show();
};


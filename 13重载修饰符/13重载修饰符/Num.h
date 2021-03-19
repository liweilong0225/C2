#pragma once
class CNum
{
public:
	int m_nNum;
public:
	CNum(void);
	~CNum(void);
public:
	int operator=(int num);
	int operator+(int num);
	int operator++();
	int operator++(int);

};


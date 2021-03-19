#include "Num.h"


CNum::CNum(void)
{
	m_nNum = 0;
}


CNum::~CNum(void)
{
}
int CNum::operator=(int num)
{
	m_nNum = num;
	return m_nNum;
}
int CNum::operator+(int num)
{
	return m_nNum+num;
}
int CNum::operator++()
{
	m_nNum = m_nNum+1;
	return m_nNum;
}
int CNum::operator++(int)
{
	int pTemp = m_nNum;
	m_nNum = m_nNum+1;
	return pTemp;
}

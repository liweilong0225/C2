#include "House.h"


CHouse::CHouse(void)
{
}


CHouse::~CHouse(void)
{
	//ɾ�����������е����Ӷ���
	list<CCage*>::iterator ite = m_lstCage.begin();
	while (ite != m_lstCage.end())
	{
		delete (*ite);
		++ite;
	}
}

#include "House.h"


CHouse::CHouse(void)
{
}


CHouse::~CHouse(void)
{
	//删除链表中所有的笼子对象
	list<CCage*>::iterator ite = m_lstCage.begin();
	while (ite != m_lstCage.end())
	{
		delete (*ite);
		++ite;
	}
}

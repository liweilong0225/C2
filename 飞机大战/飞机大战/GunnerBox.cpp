#include "GunnerBox.h"


CGunnerBox::CGunnerBox(void)
{
}


CGunnerBox::~CGunnerBox(void)
{
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while (ite != m_lstGunner.end())
	{
		delete(*ite);	//删除炮弹对象
		ite++;
	}
}
void CGunnerBox::AllGunnerMove()
{
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while (ite != m_lstGunner.end())
	{
		if ((*ite)->y<0)
		{
			delete(*ite);
			ite = m_lstGunner.erase(ite);
		}
		else
		{
			(*ite)->MoveGunner();
			ite++;
		}
	}
}
void CGunnerBox::AllGunnerShow(HDC hdc)
{
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while (ite != m_lstGunner.end())
	{
		(*ite)->ShowGunner(hdc);	//显示所有对象
		ite++;
	}
}
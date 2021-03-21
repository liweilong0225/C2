#include "Anne.h"
#include<iostream>
using namespace std;

CAnne::CAnne(void)
{
}


CAnne::~CAnne(void)
{
}
void CAnne::AndAnimalPlay(CHouse& house,int nID)
{
	list<CCage*>::iterator ite = house.m_lstCage.begin();
	while (ite != house.m_lstCage.end())
	{
		//找nID
		if ((*ite)->m_nID == nID)
		{
			if ((*ite)->m_pAnimal == 0)
			{
				cout<<"嘤嘤嘤~"<<endl;
			}
			else
			{
				cout<<"嘿嘿嘿~"<<endl;
				(*ite)->m_pAnimal->Play();
			}
			return;
		}
		++ite;
	}
	cout<<"没找到这个笼子！"<<endl;
}
void CAnne::LookLook(CHouse& house)
{
	//遍历链表
	list<CCage*>::iterator ite = house.m_lstCage.begin();
	while (ite != house.m_lstCage.end())
	{
		cout<<(*ite)->m_nID<<".";
		if((*ite)->m_pAnimal == 0)
			cout<<"----------NULL----------"<<endl;
		else
			(*ite)->m_pAnimal->Show();
		++ite;
	}
}
bool CAnne::PushAnimel(CHouse& house,int nID,CAnimal* pAnimal)
{
	list<CCage*>::iterator ite = house.m_lstCage.begin();
	while (ite != house.m_lstCage.end())
	{
		//查找输入nID编号的笼子
		if ((*ite)->m_nID == nID)
		{
			//找到了判断笼子内是否有动物
			if ((*ite)->m_pAnimal == 0)
			{
				//没有动物，该笼子的动物指针指向传进来的pAnimal，返回ture
				(*ite)->m_pAnimal = pAnimal;
				return true;
			}
			else
			{
				//有动物不能放，返回false
				cout<<"放失败了！"<<endl;
				return false;
			}
		}
		++ite;
	}
	//没有找到输入的ID
	return false;
}
void CAnne::PushCage(CHouse& house,int nCount)
{
	for (int i = 0; i < nCount; i++)
	{
		//创建笼子对象
		CCage* pCage = new CCage;
		//修改ID
		if(house.m_lstCage.empty() == true)
			pCage->m_nID = 1;
		else
			pCage->m_nID = house.m_lstCage.back()->m_nID+1;
		//添加到house的链表里
		house.m_lstCage.push_back(pCage);
	}
}
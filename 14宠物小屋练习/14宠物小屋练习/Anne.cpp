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
		//��nID
		if ((*ite)->m_nID == nID)
		{
			if ((*ite)->m_pAnimal == 0)
			{
				cout<<"������~"<<endl;
			}
			else
			{
				cout<<"�ٺٺ�~"<<endl;
				(*ite)->m_pAnimal->Play();
			}
			return;
		}
		++ite;
	}
	cout<<"û�ҵ�������ӣ�"<<endl;
}
void CAnne::LookLook(CHouse& house)
{
	//��������
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
		//��������nID��ŵ�����
		if ((*ite)->m_nID == nID)
		{
			//�ҵ����ж��������Ƿ��ж���
			if ((*ite)->m_pAnimal == 0)
			{
				//û�ж�������ӵĶ���ָ��ָ�򴫽�����pAnimal������ture
				(*ite)->m_pAnimal = pAnimal;
				return true;
			}
			else
			{
				//�ж��ﲻ�ܷţ�����false
				cout<<"��ʧ���ˣ�"<<endl;
				return false;
			}
		}
		++ite;
	}
	//û���ҵ������ID
	return false;
}
void CAnne::PushCage(CHouse& house,int nCount)
{
	for (int i = 0; i < nCount; i++)
	{
		//�������Ӷ���
		CCage* pCage = new CCage;
		//�޸�ID
		if(house.m_lstCage.empty() == true)
			pCage->m_nID = 1;
		else
			pCage->m_nID = house.m_lstCage.back()->m_nID+1;
		//��ӵ�house��������
		house.m_lstCage.push_back(pCage);
	}
}
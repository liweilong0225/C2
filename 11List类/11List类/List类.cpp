#include<iostream>
#include<string>
using namespace std;

class CStudent
{
private:
	int m_nNum;
	string m_strName;
public:
	CStudent()
	{
		m_nNum = 0;
		m_strName = "";
	}
public:
	void SetInfo(int nNum,string strName)
	{
		m_nNum = nNum;
		m_strName = strName;
	}
	void Show()
	{
		cout<<m_nNum<<":"<<m_strName<<endl;
	}
};

class CList
{
private:
	struct Node
	{
		CStudent nValue;
		Node* pNext;
	};
	Node* m_pHead;
	Node* m_pEnd;
	int m_nSize;
public:
	CList()
	{
		m_pHead = 0;
		m_pEnd = 0;
		m_nSize = 0;
	}
	~CList()
	{
		Node* pDel = 0;
		while (m_pHead!=0)
		{
			pDel = m_pHead;
			m_pHead = m_pHead->pNext;
			delete pDel;
			pDel = 0;
		}
	}
public:
	void Push_Back(CStudent nVal)
	{
		Node* pNode = new Node;
		pNode->nValue = nVal;
		pNode->pNext = 0;
		
		if (m_pHead == 0)
		{
			m_pHead = pNode;
			m_pEnd = pNode;
		}
		else
		{
			m_pEnd->pNext = pNode;
			m_pEnd = pNode;
		}
		m_nSize++;
	}
	void Pop_Front()
	{
		if(m_pHead == 0)
			return;
		if (m_pHead->pNext == 0)
		{
			delete m_pHead;
			m_pHead = 0;
			m_pEnd = 0;
			m_nSize = 0;
		}
		else
		{
			Node* pDel = m_pHead;
			m_pHead = m_pHead->pNext;
			delete pDel;
			pDel = 0;
			m_nSize--;
		}
	}
	void Show()
	{
		Node* pTemp = m_pHead;
		while (pTemp != 0)
		{
			pTemp->nValue.Show();
			pTemp = pTemp->pNext;
		}
		cout<<"size:"<<m_nSize<<endl;
	}
};
int main()
{
	CStudent st1;
	st1.SetInfo(1,"AAAA");
	CStudent st2;
	st2.SetInfo(2,"BBBB");
	CStudent st3;
	st3.SetInfo(3,"CCCC");

	CList aa;
	aa.Push_Back(st1);
	aa.Push_Back(st2);
	aa.Push_Back(st3);
	aa.Show();

	system("pause");
	return 0;
}
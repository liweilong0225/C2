#include<iostream>
#include<list>
#include<algorithm>
#include<time.h>
using namespace std;

void Show(int a)
{
	cout<<a<<" ";
}
int main()
{
	list<int> lst1;
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(1);
	lst1.push_back(6);
	lst1.push_back(7);
	lst1.push_back(0);
	lst1.push_back(9);

	list<int>::reverse_iterator revite = lst1.rbegin();//��ת������
	while (revite != lst1.rend())
	{
		//cout<<*revite<<" ";//��ת����
		if (*revite == 6)//�������ʱ��6ɾ��
		{
			//lst1.erase(--(revite.base()));//revite.base()ת��iterator������ת��ȥ
			lst1.erase((++revite).base());//ת��iterator��һ��Ԫ�صľ��룬��Ҫ����
			break;
		}
		++revite;
	}
	::for_each(lst1.begin(),lst1.end(),&Show);

	system("pause");
	return 0;
}
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

	list<int>::reverse_iterator revite = lst1.rbegin();//翻转迭代器
	while (revite != lst1.rend())
	{
		//cout<<*revite<<" ";//反转链表
		if (*revite == 6)//反向遍历时将6删除
		{
			//lst1.erase(--(revite.base()));//revite.base()转成iterator，并翻转回去
			lst1.erase((++revite).base());//转成iterator差一个元素的距离，需要调整
			break;
		}
		++revite;
	}
	::for_each(lst1.begin(),lst1.end(),&Show);

	system("pause");
	return 0;
}
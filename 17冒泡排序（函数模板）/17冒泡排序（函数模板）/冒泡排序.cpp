#include<iostream>
using namespace std;

template<typename TT>
void BubbleSort(TT* arr,int n,bool (*pfnRule)(TT,TT))
{
	for (int i = 0; i < n-1; i++)			//排序次数
	{
		for (int j = 0; j < (n-1)-i; j++)	//比较次数
		{
			if (pfnRule(arr[j],arr[j+1]))
			{
				TT temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
bool Rule1(int x,int y)			//从小到大排序
{
	return x>y;
}
bool Rule2(double x,double y)	//从大到小排序
{
	return x<y;
}
bool Rule3(int x,int y)				//被3整除的放左边
{
	return x%3;
}
int main()
{
	int arr1[10]={1,4,7,2,5,8,3,6,9,0};
	BubbleSort(arr1,10,Rule1);
	for(int nVal:arr1)
		cout<<nVal<<"	";
	cout<<endl<<"=============================="<<endl;

	double arr2[10] = {1.1,4.4,7.7,2.2,5.5,8.8,3.3,6.6,9.9,0.1};
	BubbleSort(arr2,10,Rule2);
	for(double nVal:arr2)
		cout<<nVal<<"	";
	cout<<endl<<"=============================="<<endl;

	BubbleSort(arr1,10,Rule3);
	for(int nVal:arr1)
		cout<<nVal<<"	";
	cout<<endl<<"============================="<<endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<hash_map>
#include<algorithm>
using namespace std;

//hash_map �ڲ����ڲ��ṹ��hash_table(��ϣ��)�����ҵ�Ч����O(1);

int main()
{
	hash_map<char,int> hp;
	FILE* fp = 0;
	fopen_s(&fp,"aa.txt","rb");

	char c;
	while ((c = fgetc(fp)) != EOF)
	{
		if (hp.count(c) == 0)
			hp[c] = 1;
		else
			hp[c]++;
	}
	fclose(fp);

	//==========================================
	hash_map<char,int>::iterator ite = hp.begin();
	char cMax = ite->first;//ͷֵ
	int nMax = ite->second;//ʵֵ
	while (ite != hp.end())
	{
		if (ite->second > nMax)
		{
			cMax = ite->first;
			nMax = ite->second;
		}
		++ite;
	}
	cout<<cMax<<" "<<nMax<<endl;

	system("pause");
	return 0;
}
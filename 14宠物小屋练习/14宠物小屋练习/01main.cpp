#include<iostream>
#include"Cat.h"
#include"Dog.h"
#include"Snake.h"
#include"House.h"
#include"Anne.h"
using namespace std;

int main()
{
	CAnimal* p1 = new CCat;
	CAnimal* p2 = new CDog;
	CAnimal* p3 = new CSnake;
	p1->Init("咪咪","白色","母");
	p2->Init("大黄","黄色","公");
	p3->Init("小青","绿色","公");

	p1->Show();
	p2->Show();
	p3->Show();

	p1->Play();
	p2->Play();
	p3->Play();

	CHouse house;
	CAnne anne;

	anne.PushCage(house,5);
	anne.LookLook(house);
	cout<<"===================================="<<endl;
	anne.PushAnimel(house,1,p1);
	anne.PushAnimel(house,2,p2);
	anne.PushAnimel(house,3,p3);
	anne.LookLook(house);

	anne.AndAnimalPlay(house,1);

	system("pause");
	return 0;
}
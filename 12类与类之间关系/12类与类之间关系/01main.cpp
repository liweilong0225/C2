#include<iostream>
#include"Person.h"
#include<time.h>
#include"Family.h"

using namespace std;

int main()
{
	//srand((unsigned int)time(0));
	//CPerson ps;
	//CComputer cp;
	//CFriend ff;
	//ps.Do();
	//ps.Coding(cp);
	//ps.FindFirend(&ff);
	//ps.LOL();

	//-----------------------------
	CComputer cp;
	CFamily fa;

	CPerson* ps1 = new CPerson;
	CPerson* ps2 = new CPerson;
	CPerson* ps3 = new CPerson;
	CPerson* ps4 = new CPerson;
	CPerson* ps5 = new CPerson;

	fa.PushPerson(ps1);
	fa.PushPerson(ps2);
	fa.PushPerson(ps3);
	fa.PushPerson(ps4);
	fa.PushPerson(ps5);

	fa.AllPersonCoding(cp);

	system("pause");
	return 0;
}
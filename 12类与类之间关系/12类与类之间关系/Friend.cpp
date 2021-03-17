#include "Friend.h"
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

CFriend::CFriend(void)
{
	rp = rand()%10;
}


CFriend::~CFriend(void)
{
}
void CFriend::Play()
{
	cout<<"CFriend::Play"<<endl;
}

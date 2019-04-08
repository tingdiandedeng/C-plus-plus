#include<iostream>
#include"head.h"
#include<string>
using namespace std;
int main()
{
	iWatch b(23, 00, 15, "zhang");
	b.write();
	b.Set(23, 00, 15, E11);
	b.write();
	return 0;
}
#include"head.h"
#include<iostream>
using namespace std;
int main()
{
	Rational rat0;
	cout << rat0 << endl;
	Rational rat1 = -rat0;
	cout << rat1 << endl;
	Rational rat2 = rat1 + 34;
	cout << rat2 << endl;
	Rational rat3;
	rat3 = 12 + rat2;
	cout << rat3 << endl;
	return 0;
}
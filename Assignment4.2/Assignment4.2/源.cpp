#include"head.h"
#include<iostream>
using namespace std;
Rational::Rational(int n, int d)
{
	if (d == 0)
		cout << "illegal!\n";
	else
	{
		a = n;
		b = d;
	}
}
float operator+(float& f,Rational& R)
{
	float c=(R.a / R.b);
	c = f + c;
	return c;
}
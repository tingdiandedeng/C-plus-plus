#include<iostream>
using namespace std;
class Rational
{
public:
	Rational(int = 2, int = 3);
	friend float operator+(float&,Rational&);
private:
	float a, b;//num(·Ö×Ó)£¬den(·ÖÄ¸)
};

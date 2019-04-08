#include<iostream>
using namespace std;
class Rational
{
public:
	Rational(int = 2, int = 3);
	friend ostream& operator<<(ostream&, Rational&);
	Rational operator+(Rational&);
	Rational operator-(Rational&);
	Rational operator-();
	Rational operator+(int);
	friend Rational operator+(int, Rational&);
private:
	int a, b;//a(·Ö×Ó)£¬b(·ÖÄ¸)
};

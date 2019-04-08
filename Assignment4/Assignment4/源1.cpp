#include"head.h"
#include<iostream>
using namespace std;
Rational::Rational(int n , int d )
{
	if (d == 0)
		cout << "illegal!\n";
	else
	{
		a = n;
		b = d;
	}
}
ostream& operator<<(ostream& out, Rational& r)
{
	if (r.a == r.b)
	{
		out << "1"<< endl;
		return out;
	}
	else
	{
		out << r.a << "/" << r.b;
		return out;
	}
}
Rational Rational::operator+(Rational& R)
{
	int n = (this->a*R.b) + (this->b*R.a);
	int d = this->b*R.b;
	int max = n;
	if (d < n)
		max = d;
	for (int i=1; i <= max; i++)
	{
		if (n%i == 0 && d%i == 0)
		{
			n = n / i;
			d = d / i;
		}
		else
		{ }
	}
	return Rational(n, d);
}
Rational Rational::operator-(Rational& R)
{
	Rational r(-R.a, R.b);
	return (r + *this);
}
Rational Rational::operator-()
{
	return Rational(-this->a, this->b);
}
Rational Rational::operator+(int a)
{
	return Rational(this->a + (this->b*a), this->b);
}
Rational operator+(int a, Rational& R)
{
	return Rational (a*R.b + R.a, R.b);
}
#include<iostream>
#include<string>
using namespace std;
class Rational
{
public:
	Rational(int = 2, int = 3);
	Rational(string, string);
	friend ostream& operator<<(ostream&, Rational&);
	Rational operator+(Rational&);
private:
	string num, den;//num(·Ö×Ó)£¬den(·ÖÄ¸)
};
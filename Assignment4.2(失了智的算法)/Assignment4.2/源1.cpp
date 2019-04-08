#include<iostream>
#include"head.h"
#include<string>
using namespace std;
int main()
{
	Rational sum(0,1);
	for (int i = 1; i <= 10; i++)
	{
		Rational A(i, i + 1);
		sum = sum + A;
		cout << sum << endl;
	}
	return 0;
}
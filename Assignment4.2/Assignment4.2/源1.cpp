#include"head.h"
#include<iostream>
using namespace std;
int main()
{
	float sum = 0;
	for (int i = 1; i <= 49; i++)
	{
		Rational A(i, i + 1);
		sum = sum + A;
	}
	cout << sum << endl;
	return 0;
}
#include"head.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 30;
int Length(string str);
int Length(string str)
{
	int count=0;
	for (int i = 0; str[i] != 0 ; i++)
	{
		if(str[i]!=42)
			count++;
		else{}
	}
	return count;
}
Rational::Rational(int n, int d)
{
	string str5(N, 42);
	string str6(N, 42);
	num = str5;
	den = str6;
	if (d == 0)
		cout << "illegal!\n";
	else
	{
		if(n<10)
			num[N-1] = n+48;
		else
		{
			num[N - 1] = (n%10) + 48;
			num[N - 2] = (n / 10) + 48;
		}
		if (d<10)
			den[N - 1] = d + 48;
		else
		{
			den[N - 1] = (d % 10) + 48;
			den[N - 2] = (d / 10) + 48;
		}
	}
}
Rational::Rational(string n, string d)
{
	num = n;
	den = d;
}
ostream& operator<<(ostream& out, Rational& r)
{
	if (r.num == r.den)
	{
		out << "1" << endl;
		return out;
	}
	else
	{
		int i;
		for (i = 0; i < N; i++)
		{
			if(r.num[i]!=42)
				out << r.num[i];
			else
			{ }
		}	
		out << "/";
		for (i = 0; i < N; i++)
		{
			if (r.den[i] != 42)
				out << r.den[i];
			else
			{}
		}
	}
	return out;
}
Rational Rational::operator+(Rational& R)
{
	string n(N, 42), d(N, 42);
	string A(N, 42), sum1(N, 42),sum2(N, 42);
	int L1, L2, L3, L4;//分别为*this、R的分母长度与*this、R的分子长度
	int b = 0;//进位b
	int a = 0;//当前位
	int k = 0;//字符位置参数
	L1 = Length(this->den);
	L2 = Length(R.den);
	L3 = Length(this->num);
	L4 = Length(R.num);
	for (int i = 0; i < min(L1, L2); i++)
	{
		k = 0;
		for (int j = 0; j < max(L1, L2); j++)
		{
			if (j == 0)
				b = 0;
			else{ }
			a = (this->den[N - i - 1] - 48)*(R.den[N - j - 1] - 48) % 10;
			A[k++] = a + b+48;
			b = (this->den[N - i - 1] - 48)*(R.den[N - j - 1] - 48) / 10;
		}
		if (k == max(L1, L2) && b != 0)
			A[k] = b + 48;
		else {}
		if(i== 0)
			sum1 = A;
		else
		{
			if (Length(A)+1 == Length(sum1))
			{
				for (k = 0; k < Length(sum1); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum1[k] = sum1[0];
					}
					else 
					{
						a = ((A[k-1] - 48) + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k-1] - 48) + (sum1[k] - 48)) / 10;
					}
				}
				if (b != 0)
					sum1[k] = b + 48;
			}
			else
			{
				for (k = 0; k < min(Length(A)+1, Length(sum1)); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum1[k] = sum1[0];
					}
					else 
					{
						a = ((A[k-1] - 48) + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k-1] - 48) + (sum1[k] - 48)) / 10;
					}
					
				}
				for (k; k < max(Length(A)+1, Length(sum1)); k++)
				{
					if (Length(A)+1 < Length(sum1))
					{
						a = (b + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b= ((b - 48) + (sum1[k] - 48)) / 10;
					}
					else 
					{
						a = ((A[k - 1] - 48) + (b - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (b - 48)) / 10;
					}
					if (k == max(Length(A) + 1, Length(sum1)) && b != 0)
						sum1[k] = b + 48;
					else{}
				}
			}
		}
	}
	string t(sum1.rbegin(), sum1.rend());
	d = t;
	string str1(N, 42);
	string str2(N, 42);
	sum1 = str1; A = str2;
	for (int i = 0; i < min(L3, L2); i++)
	{
		k = 0;
		for (int j = 0; j < max(L3, L2); j++)
		{
			if (j == 0)
				b = 0;
			else {}
			a = (this->num[N - i - 1] - 48)*(R.den[N - j - 1] - 48) % 10;
			A[k++] = a + b + 48;
			b = (this->num[N - i - 1] - 48)*(R.den[N - j - 1] - 48) / 10;
			
		}
		if (k == max(L3, L2) && b != 0)
			A[k] = b + 48;
		else {}
		if (i == 0)
			sum1 = A;
		else
		{
			if (Length(A) + 1 == Length(sum1))
			{
				for (k = 0; k < Length(sum1); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum1[k] = sum1[0];
					}
					else
					{
						a = ((A[k - 1] - 48) + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (sum1[k] - 48)) / 10;
					}
				}
				if (b != 0)
					sum1[k] = b + 48;
			}
			else
			{
				for (k = 0; k < min(Length(A) + 1, Length(sum1)); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum1[k] = sum1[0];
					}
					else
					{
						a = ((A[k - 1] - 48) + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (sum1[k] - 48)) / 10;
					}

				}
				for (k; k < max(Length(A) + 1, Length(sum1)); k++)
				{
					if (Length(A) + 1 < Length(sum1))
					{
						a = (b + (sum1[k] - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((b - 48) + (sum1[k] - 48)) / 10;
					}
					else
					{
						a = ((A[k - 1] - 48) + (b - 48)) % 10;
						sum1[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (b - 48)) / 10;
					}
					if (k == max(Length(A) + 1, Length(sum1)) && b != 0)
						sum1[k] = b+48;
					else{}
				}
			}
		}
	}
	string str3(N, 42);
	string str4(N, 42);
	sum2 = str3; A = str4;
	for (int i = 0; i < min(L1, L4); i++)
	{
		k = 0;
		for (int j = 0; j < max(L1, L4); j++)
		{
			if (j == 0)
				b = 0;
			else {}
			a = (this->den[N - i - 1] - 48)*(R.num[N - j - 1] - 48) % 10;
			A[k++] = a + b + 48;
			b = (this->den[N - i - 1] - 48)*(R.num[N - j - 1] - 48) / 10;
			
		}
		if (k == max(L1, L4) && b != 0)
			A[k] = b + 48;
		else {}
		if (i == 0)
			sum2 = A;
		else
		{
			if (Length(A) + 1 == Length(sum2))
			{
				for (k = 0; k < Length(sum2); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum2[k] = sum2[0];
					}
					else
					{
						a = ((A[k - 1] - 48) + (sum2[k] - 48)) % 10;
						sum2[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (sum2[k] - 48)) / 10;
					}
				}
				if (b != 0)
					sum2[k] = b + 48;
			}
			else
			{
				for (k = 0; k < min(Length(A) + 1, Length(sum2)); k++)
				{
					if (k == 0)
					{
						b = 0;
						sum2[k] = sum2[0];
					}
					else
					{
						a = ((A[k - 1] - 48) + (sum2[k] - 48)) % 10;
						sum2[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (sum2[k] - 48)) / 10;
					}

				}
				for (k; k < max(Length(A) + 1, Length(sum2)); k++)
				{
					if (Length(A) + 1 < Length(sum2))
					{
						a = (b + (sum2[k] - 48)) % 10;
						sum2[k] = a + b + 48;
						b = ((b - 48) + (sum2[k] - 48)) / 10;
					}
					else
					{
						a = ((A[k - 1] - 48) + (b - 48)) % 10;
						sum2[k] = a + b + 48;
						b = ((A[k - 1] - 48) + (b - 48)) / 10;
					}
					if (k == max(Length(A) + 1, Length(sum2)) && b != 0)
						sum2[k] = b + 48;
					else {}
				}
			}
		}
	}
	for (k = 0; k < min(Length(sum1), Length(sum2)); k++)
	{
		if (k == 0)
			b = 0;
		else {}
		if (Length(sum1) == Length(sum2))
		{
			for (k = 0; k < Length(sum1); k++)
			{
				if (k == 0)
					b = 0;
				else {}
				a = ((sum1[k] - 48) + (sum2[k] - 48)) % 10;
				n[k] = a + b + 48;
				b = ((sum1[k] - 48) + (sum2[k] - 48)) / 10;
			}
			if (b != 0)
				n[k] = b + 48;
		}
		else
		{
			for (k = 0; k < min(Length(sum1), Length(sum2)); k++)
			{
				if (k == 0)
					b = 0;
				else
				{
					a = ((sum1[k] - 48) + (sum2[k] - 48)) % 10;
					n[k] = a + b + 48;
					b = ((sum1[k] - 48) + (sum2[k] - 48)) / 10;
				}

			}
			for (k; k < max(Length(sum1), Length(sum2)); k++)
			{
				if (Length(sum1) < Length(sum2))
				{
					a = (b + (sum2[k] - 48)) % 10;
					n[k] = a + b + 48;
					b = ((b - 48) + (sum2[k] - 48)) / 10;
				}
				else
				{
					a = ((sum1[k] - 48) + (b - 48)) % 10;
					n[k] = a + b + 48;
					b = ((sum1[k] - 48) + (b - 48)) / 10;
				}
				if (k == max(Length(sum1), Length(sum2)) && b != 0)
					n[k] = b + 48;
				else {}
			}
		}
	}
	string s(n.rbegin(), n.rend());
	n = s;
	return Rational(n,d);
}
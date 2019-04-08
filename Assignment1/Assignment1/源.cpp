#include<iostream>
#include"Arrays.h"
using namespace std;
int main()
{
	int i; int j;
	Int_arrays INT;
	Char_arrays CHAR;
	INT.read();
	INT.sorts_Int();
	CHAR.read();
	CHAR.sorts_Char();
	cout << "输入你想查询的数组（1：数字数组；0：字符数组）与第几位:" << endl;
	cin >> i >> j;
	if (i == 1)
		INT.print_Int(j);
	else if (i == 0)
		CHAR.print_Char(j);
	else
		cout << "Wrong!" << endl;
	INT.printAll_Int();
	CHAR.printAll_Char();
	return 0;
}
Char_arrays::Char_arrays()
{
	number = 8;
}
Int_arrays::Int_arrays()
{
	number = 8;
}
void Int_arrays::read()
{
	int i;
	cout << "输入8位数字数组:" << endl;
	for (i = 0; i < 8; i++)
	{
		cin >> A[i];
	}
}
void Char_arrays::read()
{
	int i;
	cout << "输入8位字符数组:" << endl;
	for (i = 0; i < 8; i++)
	{
		cin >> B[i];
	}
}
void Int_arrays::sorts_Int()//排列整数数列
{
	int a; int b; int t;
	for (a = 0; a < number; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (*(A + b) < *(A + b - 1))
			{
				t = *(A + b);
				*(A + b) = *(A + b - 1);
				*(A + b - 1) = t;
			}
		}
	}
}
void Int_arrays::print_Int(int b)//显示任意数
{
	cout << "查找的数字数组的第"<<b<<"个数为:\n";
	cout << *(A + b - 1) << endl;
}
void Int_arrays::printAll_Int()//显示所有数
{
	int i;
	cout << "排序后的数字数组为：\n";
	for (i = 0; i < number; i++)
	{
		cout << " " << *(A + i);
	}
	cout << endl;
}
void Char_arrays::sorts_Char()//排列字符数组
{
	int a; int b; char t;
	for (a = 0; a < number; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (*(B + b) < *(B + b - 1))
			{
				t = *(B + b);
				*(B + b) = *(B + b - 1);
				*(B + b - 1) = t;
			}
		}
	}
}
void Char_arrays::print_Char(int c)//输出第几个数
{
	cout << "查找的字符数组的第" << c << "个数为:\n";
	cout << *(B + c - 1) << endl;
}
void Char_arrays::printAll_Char()//输出字符数组
{
	int j;
	cout << "排序后的字符数组为：\n";
	for (j = 0; j < number; j++)
		cout << " " << *(B + j);
	cout << endl;
}
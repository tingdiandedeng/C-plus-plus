#include<iostream>
using namespace std;
void Sorts(int*);
void Sorts(char*);
int Gets(int*, int);
char Gets(char*, int);
void PrintAll(int*, char*);
int main()
{
	int A[8]; char B[8];
	int i; int a; int b; char gets; int get;
	cout << "����8λ��������:" << endl;
	for (i = 0; i < 8; i++)
		cin >> A[i];
	cout << "����8λ�ַ�����:" << endl;
	for (i = 0; i < 8; i++)
	{
		cin >> B[i];
	}
	Sorts(A);
	Sorts(B);
	cout << "��������Gets�����飨1���������飻0���ַ����飩��ڼ�λ:" << endl;
	cin >> a >> b;
	if (a == 1)
	{
		get = Gets(A, b);
		cout << get << endl;
	}
	else if (a == 0)
	{
		gets = Gets(B, b);
		cout << gets << endl;
	}
	else
		cout << "Wrong!" << endl;
	PrintAll(A, B);
	return 0;
}
void Sorts(int* A)
{
	int a; int b; int t;
	for (a = 0; a < 8; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (*(A + b) > *(A + b - 1))
			{
				t = *(A + b);
				*(A + b) = *(A + b - 1);
				*(A + b - 1) = t;
			}
		}
	}
}
void Sorts(char* B)
{
	int a; int b; char t;
	for (a = 0; a < 8; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (*(B + b) > *(B + b - 1))
			{
				t = *(B + b);
				*(B + b) = *(B + b - 1);
				*(B + b - 1) = t;
			}
		}
	}
}
int Gets(int* A, int b)
{
	cout << "Gets����������ĵ�" << b << "����Ϊ:\n";
	return *(A + b - 1);
}
char Gets(char*B, int b)
{
	cout << "Gets���ַ�����ĵ�" << b << "����Ϊ:\n";
	return *(B + b - 1);
}
void PrintAll(int* A, char* B)
{
	int i;
	cout << "��������������Ϊ��\n";
	for (i = 0; i < 8; i++)
	{
		cout << " " << *(A + i);
	}
	cout << endl;
	cout << "�������ַ�����Ϊ��\n";
	for (i = 0; i < 8; i++)
	{
		cout << " " << *(B + i);
	}
	cout << endl;
}
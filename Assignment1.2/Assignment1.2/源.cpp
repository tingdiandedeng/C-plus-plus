#include<iostream>
#include"passwordCheck.h"
using namespace std;
int main()
{
	PassWord A;
	if (A.checkPassword() == 0)
		cout << "invalid password!\n";
	else
		cout << "valid password!\n";
	return 0;
}
PassWord::PassWord()
{
		cout << "��������8λ�������֡���ĸ�����룬����������λ��\n";
			cin >> password;
}
bool PassWord::checkPassword()
{
	int i; int j = 0; int k = 0; int m = 0;
	for (i = 0;password[i]!=0 ; i++)
	{
		if ((65 <= password[i] & password[i] <= 90) || (97 <= password[i] & password[i] <= 122) || (48 <= password[i] & password[i] <= 57))
		{
			j++;
			if (48 <= password[i] && password[i] <= 57)//�ж�Ϊ����
				m++;
		}
		else
			k++;
	}
	if (j < 9 || m < 2 || k > 0)
		return false;
	else
		return true;
}
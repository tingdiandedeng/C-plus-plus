#include"head.h"

void Print(Person& p)
{
	p.print();
}
void main()
{
	Doctor D("160405319", "������", 20, "��", "���", "ר��");
	Patient P;
	P.Register();
	P.SeeDoctor(D);
	cout << "\nҽ����ϢΪ��\n";
	Print(D);
	cout << "\n������ϢΪ��\n";
	Print(P);
	system("pause");
}
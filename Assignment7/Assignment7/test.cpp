#include"head.h"

void Print(Person& p)
{
	p.print();
}
void main()
{
	Doctor D("160405319", "张升旺", 20, "男", "外科", "专家");
	Patient P;
	P.Register();
	P.SeeDoctor(D);
	cout << "\n医生信息为：\n";
	Print(D);
	cout << "\n病人信息为：\n";
	Print(P);
	system("pause");
}
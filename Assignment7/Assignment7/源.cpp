#include"head.h"

void Person::print()
{
	cout << "��ţ�" << no << endl;
	cout << "������" << name << endl;
	cout << "�Ա�" << gender << endl;
	cout << "���䣺" << age << endl;
}

void Patient::Register()
{
	cout << "****�Һ�**** \n�����������Ϣ��\n";
	cout << "���:"; cin >> no;
	cout << "������"; cin >> name;
	cout << "�Ա�"; cin >> gender;
	cout << "���䣺"; cin >> age; 
	cout << "���飺"; cin >> illness_details;
	cout << "���ң�"; cin >> department;
	cout << "�Һųɹ�\n";
}
void Patient::SeeDoctor(Doctor& d)
{
	d.diagnosis(illness_details);
	treatment_details = d.treatment();
}

void Patient::print()
{
	Person::print();
	cout << "���ң�" << department << endl;
	cout << "���飺" << illness_details << endl;
	cout << "���Ʒ�����" << treatment_details << endl;
}

void Doctor::diagnosis(string ill)
{
	cout << "\n***ҽ�����***\n";
	cout << "���˲���Ϊ��" << ill << endl;
	cout << "������Ͻ����";
	cin >> diagnosis_detail;
	cout << "�������Ʒ�����" << endl;
	cin >> treatment_details;
}

string Doctor::treatment()
{
	return treatment_details;
}

void Doctor::print()
{
	Person::print();
	cout << "���ң�" << department << endl;
	cout << "ְλ��" << professional_title << endl;;
}
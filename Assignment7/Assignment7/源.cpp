#include"head.h"

void Person::print()
{
	cout << "编号：" << no << endl;
	cout << "姓名：" << name << endl;
	cout << "性别：" << gender << endl;
	cout << "年龄：" << age << endl;
}

void Patient::Register()
{
	cout << "****挂号**** \n请输入你的信息：\n";
	cout << "编号:"; cin >> no;
	cout << "姓名："; cin >> name;
	cout << "性别："; cin >> gender;
	cout << "年龄："; cin >> age; 
	cout << "病情："; cin >> illness_details;
	cout << "科室："; cin >> department;
	cout << "挂号成功\n";
}
void Patient::SeeDoctor(Doctor& d)
{
	d.diagnosis(illness_details);
	treatment_details = d.treatment();
}

void Patient::print()
{
	Person::print();
	cout << "科室：" << department << endl;
	cout << "病情：" << illness_details << endl;
	cout << "治疗方案：" << treatment_details << endl;
}

void Doctor::diagnosis(string ill)
{
	cout << "\n***医生诊断***\n";
	cout << "病人病情为：" << ill << endl;
	cout << "输入诊断结果：";
	cin >> diagnosis_detail;
	cout << "输入治疗方案：" << endl;
	cin >> treatment_details;
}

string Doctor::treatment()
{
	return treatment_details;
}

void Doctor::print()
{
	Person::print();
	cout << "科室：" << department << endl;
	cout << "职位：" << professional_title << endl;;
}
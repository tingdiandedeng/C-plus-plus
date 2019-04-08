#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person() {}
	virtual void print()=0;
protected:
	string no, name, gender;
	int age;
};

class Doctor :public Person
{
public:
	Doctor(string No, string n, int a, string g, string d, string p) :Person()
	{
		no = No; name = n; age = a; gender = g; department = d; professional_title = p;
	}
	void diagnosis(string ill);
	string treatment();
	void print();
private:
	string department, professional_title, diagnosis_detail, treatment_details;
};

class Patient :public Person
{
public:
	Patient() :Person() {}
	void Register();
	void SeeDoctor(Doctor&);
	void print();
private:
	string illness_details, treatment_details, department;
};
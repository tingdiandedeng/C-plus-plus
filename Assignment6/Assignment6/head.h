#include<string>
#include<iostream>
using namespace std;
class Person
{
public:
	Person():name("unknown"),ID("unknown"){}
	Person(string n,string I):name(n),ID(I){}
	string getN() const { return name; }
	string getI() const { return ID; }
	void setN(string n) { name = n; }
	void setI(string I) { ID = I; }
private:
	string name;
	string ID;
};

class Teacher :virtual public Person
{
public:
	Teacher() :workingHours(0),salary(0), Person(){}
	Teacher(string n, string I, float h) :workingHours(h) { setN(n); setI(I); }
	void calculateSalary();
	void set(float s) { salary = s; }
	float getwH() const { return workingHours; }
	float getSa() const { return salary; }
private:
	float workingHours, salary;
};

class Student :virtual public Person
{
public:
	Student():studyClass("unknown"),hour(0),Person(){}
	Student(string n, string I, string C, float h):studyClass(C),hour(h){ setN(n); setI(I); }
	string getSC() const { return studyClass; }
	float getH() const { return hour; }
private:
	string studyClass;
	float hour;
};

class Teacher_Assistants :public Teacher, public Student
{
public:
	Teacher_Assistants() :Person(), Teacher(), Student() {}
	Teacher_Assistants(string n,string I,string sC,float H,float wH):
		Student(n,I,sC,H),Teacher(n,I,wH){setN(n); setI(I);}
	void calculateSalary();
};
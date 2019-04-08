#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include <time.h>
#include <conio.h>

#include <Windows.h>
#include <mmsystem.h>
#include <assert.h>
#include <stdlib.h>
#pragma comment(lib,"WinMM.Lib")

using namespace std;

void play(string);

class AddressBook;

class contact
{
public:
	contact()
	{
		Name = "null";
		Company = "null";
		PhoneNumber = "null";
		Email = "null";
		Classification = "null";
	}
	void setNumber(int n) { Number = n; }
	void print();
	void print(int);
	string getName() { return Name; }
	string getPhoneNumber() { return PhoneNumber; }
	void Edit();
	void add(int);
	void Delete();
	void Read(string, int, int);
	void Save(ofstream&);
	contact& operator=(contact&);
private:
	int Number;
	string Name;
	string Company;
	string PhoneNumber;
	string Email;
	string Classification;
};

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	void Add();
	void Edit(int);
	void Delete(int);
	bool print(int);
	bool printAll();
	bool empty() { return count; }
	string getName(int i) { return Contact[i - 1].getName(); }
	string getPhoneNumber(int i) { return Contact[i - 1].getPhoneNumber(); }
private:
	friend class SmartPhone;
	contact Contact[200];
	int count;
};

class PerInfo
{
public:
	PerInfo();
	~PerInfo();
	void Set();
	void print();
	void setHeartRate(double i) { HeartRate = i; }
	bool STR(string& );
private:
	string name;
	int age;
	double height;
	double weight;
	double BMI;
	double HeartRate;
};

class ThreeBand
{
public:
	ThreeBand() :StepNumber(0) {}
	void printPerInfo() { P.print(); }
	void setPerInfo() { P.Set(); }
	void setHertRate();
	void printTime();
	void setStepNumber();
	void Answer(SmartPhone&);
	void call(SmartPhone&);
	void call(SmartPhone&, string, string);
	void addressBook(SmartPhone&);
private:
	PerInfo P;
	int StepNumber;
};

class SmartPhone
{
public:
	SmartPhone(){}
	bool PhoneRinging() 
	{
		srand((unsigned)time(NULL));
		return rand() % (5) + 0;
	}
	bool call(string);
	AddressBook& getBook() { return book; }
private:
	AddressBook book;
};
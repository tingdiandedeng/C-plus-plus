#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Location
{
private:
	double X;/*Î³¶È·¶Î§-90~90£¬¾­¶È·¶Î§-180~180*/
	double Y;
public:
	Location(double x = 100, double y = 200) :X(x), Y(y) {}
	void Set(double x, double y) { X = x; Y = y; }
	double GetX() { return X; }
	double GetY() { return Y; }
};

class Scene
{
private:
	string Name;
	Location L;
	string Introduction;
	long NumberOfPeople;
public:
	Scene() :Name("NULL"), L(), Introduction("NULLL"), NumberOfPeople(0) {}
	Scene(string n, double x, double y, string i, long Number) :Name(n), L(x, y), Introduction(i), NumberOfPeople(Number) {}
	void SetNumberOfPeople() { NumberOfPeople++; }
	string GetName() { return Name; }
	string GetIntroduction() { return Introduction; }
	long GetNumberOfPeople() { return NumberOfPeople; }
	Location GetLocation() { return L; }
};


class Person
{
private:
	Location Now;
	Location Destination;
public:
	Person(double X1, double Y1) :Now(X1, Y1), Destination() {}
	void SetNow(double x, double y) { Now.Set(x, y); }
	void SetDestination(double x, double y) { Destination.Set(x, y); }
	Location GetNow() { return Now; }
	Location GetDestination() { return Destination; }
};

double GetDistance(Location L1, Location L2);
float GetTime(Location L1, Location L2, int NumberOfPeople);
bool PrintIntroduction(Person P, Scene s[], int count);
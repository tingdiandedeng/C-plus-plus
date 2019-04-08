#include<string>
using namespace std;
class Time
{
public:
	Time():hrs(0),mins(0),secs(0){}
	Time(int a, int b, int c):hrs(a),mins(b),secs(c){}
	~Time(){}
	void Set(int a, int b, int c) { hrs = a; mins = b; secs = c; }
	void write() const;
	int Hours() const { return hrs; }
	int Minutes() const { return mins; }
	int Seconds() const { return secs; }
	Time& operator++();
	Time& operator--();
private:
	int hrs, mins, secs;
};
enum ZoneType{W11=-11, W10, W9, W8, W7, W6, W5, W4, W3, W2, W1,
	zero,E1,E2,E3,E4,E5,E6,E7,E8,E9,E10,E11,WE12};
class ExtTime :public Time
{
public:
	ExtTime():Time(){}
	ExtTime(int a, int b, int c, ZoneType z=E8) :Time(a, b, c),zone(z){}
	~ExtTime(){}
	void Set(int a, int b, int c, ZoneType z=E8);
	void write() const;
	ExtTime& operator++();
	ExtTime& operator--();
	ZoneType Zone() const { return zone; }
private:
	ZoneType zone;
};
class iWatch
{
public:
	iWatch(int a, int b, int c, string n) :t(a, b, c), name(n){}
	void write() const { t.write(); }
	void Set(int a, int b, int c, ZoneType z) 
	{t.Set(a, b, c,  z);}
private:
	string name;
	ExtTime t;
};
#include<iostream>
#include"head.h"
#include<string>
using namespace std;
void Time::write() const
{
	cout << "现在的时间为：";
	if (hrs < 10)
		cout << "0" << hrs << ":";
	else
		cout << hrs << ":";
	if (mins < 10)
		cout << "0" << mins << ":";
	else
		cout << mins << ":";
	if (secs < 10)
		cout << "0" << secs <<endl;
	else
		cout << secs << endl;
}
Time& Time::operator++()
{
	if (hrs = 24)
		hrs = 1;
	else
		hrs++;
	return *this;
}
Time& Time::operator--()
{
	if (hrs = 0)
		hrs = 23;
	else
		hrs--;
	return *this;
}
void ExtTime::Set(int a, int b, int c, ZoneType z)
{
	a = a - (E8 - z);
	if (a < 0)
		a = a + 24;
	else if(a >= 24)
		a = a - 24;
	else{}
	Time::Set(a, b, c);
	zone = z;
}
void ExtTime::write() const
{
	Time::write();
	string A[24] = { "西十一", "西十", "西九", "西八", "西七", "西六", "西五", "西四", "西三", "西二", "西一",
		"中时区", "东一","东二","东三","东四","东五","东六","东七","东八","东九","东十","东十一","东西十二" };
	cout << "时区为：" << A[zone+11]<<endl;
}
ExtTime& ExtTime::operator++()
{
	Time::operator++();
	if (zone < 12)
		zone = ZoneType(zone + 1 + 11);
	else if (zone == WE12)
		zone = ZoneType(0);
	return *this;
}
ExtTime& ExtTime::operator--()
{
	Time::operator--();
	if (zone > 0)
		zone = ZoneType(zone - 1 + 11);
	else if (zone == W11)
		zone = ZoneType(23);
	return *this;
}
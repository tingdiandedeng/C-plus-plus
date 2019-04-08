#include<iostream>
#include"head.h"
#include<string>
using namespace std;
void Time::write() const
{
	cout << "���ڵ�ʱ��Ϊ��";
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
	string A[24] = { "��ʮһ", "��ʮ", "����", "����", "����", "����", "����", "����", "����", "����", "��һ",
		"��ʱ��", "��һ","����","����","����","����","����","����","����","����","��ʮ","��ʮһ","����ʮ��" };
	cout << "ʱ��Ϊ��" << A[zone+11]<<endl;
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
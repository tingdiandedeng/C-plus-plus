#include"head.h"
void Teacher::calculateSalary()
{
	set(4500 + workingHours * 30);
}
void Teacher_Assistants::calculateSalary()
{
	set(getwH() * 25);
}
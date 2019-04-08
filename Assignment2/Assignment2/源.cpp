#include<iostream>
#include<cstdlib>
#include<ctime>
#include"CAT.h"
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
int Cat::Egr = 0;
int Cat::Ebl = 0;
int Cat::Ebr = 0;
int Cat::Fbl = 0;
int Cat::Fbr = 0;
int Cat::Fgr = 0;
int Cat::count = 0;
int main()
{
	int i; int j; char flag;
	cout << "Please enter a number to indicating the size of the cage:\n";
	cin >> i;
	Cat* cats = new Cat[i];
	if (cats == NULL)
		cout << "Error: memory could not be allocated";
	else
	{
		for (j = 0; j < i; j++)
		{
			flag = NULL;
			cout << "Press enter you can create a cat.Press 1 to end:\n";
			if(j==0)
			cin.get();
			flag = cin.get();
			if (flag == '\n')
			{
				cats[j].createCat();
				cats[j].printCat();
				if (cats[i].fightCat())
					cout << "They fight.\n";
				else
					cout << "They don't fight.\n\n";
			}
			if (flag == '1')
				break;
		}
	}
	delete cats;
	return 0;
}
Cat::Cat()
{
	eyeColor = "unknown";
	furColor = "unknown";
	furLength = "unknown";
}
void Cat::createCat()
{
	int a = random(1, 3);
	switch (a)
	{
	case 1:eyeColor = "green"; Egr++; break;
	case 2:eyeColor = "blue"; Ebl++; break;
	case 3:eyeColor = "brown"; Ebr++; break;
	}
	a = random(1, 3);
	switch (a)
	{
	case 1:furColor = "black"; Fbl++; break;
	case 2:furColor = "gray"; Fgr++; break;
	case 3:furColor = "brown"; Fbr++; break;
	}
	a = random(1, 2);
	switch (a)
	{
	case 1:furLength = "long"; break;
	case 2:furLength = "short"; break;
	}
	count++;
}
void Cat::printCat() const
{
	cout << "You created a " << eyeColor << " eye and " << furColor << " " << furLength << " fur cat.\n";
	cout << "You have created " << count << " cat(s).\n";
}
bool Cat::fightCat()
{
	if (Fgr + Fbr == 0 || Fbl + Fbr == 0 || Fbl + Fgr == 0)
		if (Ebl + Ebr == 0 || Egr + Ebr == 0 || Egr + Ebl == 0)
			return false;
		else
			return true;
	if(((Fgr==Fbr)&Fbl==0)|| ((Fgr == Fbl)&Fbr == 0)|| ((Fbl == Fbr)&Fgr == 0))
		if (Ebl + Ebr == 0 || Egr + Ebr == 0 || Egr + Ebl == 0)
			return false;
		else
			return true;
	if(Fbl==Fbr==Fgr)
		if (Ebl + Ebr == 0 || Egr + Ebr == 0 || Egr + Ebl == 0)
			return false;
		else
			return true;
}
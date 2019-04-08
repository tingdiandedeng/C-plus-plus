#include"head.h"

BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode 
	// string. 
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);
	assert(dwSize >= dwMinSize);

	// Convert headers from ASCII to Unicode.
	MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);
	return TRUE;
}

void play(string s)
{
	wchar_t wText[30] = { 0 };
	MByteToWChar(s.c_str(), wText, sizeof(wText) / sizeof(wText[0]));
	PlaySound(wText, NULL, SND_FILENAME | SND_SYNC);
}

AddressBook::AddressBook()
{
	string str;
	count = 0;
	ifstream read("data.txt");
	read >> str;
	if (str.length() == 0)
	{
		read.close();
		return;
	}
	int p1 = 0, p2 = 0, i = 0;
	while (p2 != (str.length() - 1))
	{
		p1 = str.find('{', p2);
		p2 = str.find('}', p1 + 1);
		Contact[i++].Read(str, p1, p2);
		Contact[i - 1].setNumber(i);
	}
	count = i;
	read.close();
}

AddressBook::~AddressBook()
{
	ofstream Save("data.txt");
	for (int i = 0; i<count; i++)
	{
		Save << '{';
		Contact[i].Save(Save);
		Save << '}';
	}
	Save.close();
}

void AddressBook::Add()
{
	int k;
	k = count++;
	Contact[k].add(k);
}

void AddressBook::Edit(int i)
{
	Contact[i - 1].Edit();
}

void AddressBook::Delete(int i)
{
	Contact[--i].Delete(); count--;
	for (i; i < count; i++)
	{
		contact temp = Contact[i];
		Contact[i] = Contact[i + 1];
		Contact[i + 1] = temp;
		Contact[i].setNumber(i + 1);
	}
}

bool AddressBook::print(int i)
{
	if (i<1 || i>count)
	{
		cout << "               ���޴��ˣ�\n";
		cout << "               ";
		system("pause");
		system("cls");
		return false;
	}
	cout << "               ************************************************************************************\n";
	Contact[i - 1].print();
	cout << "               ************************************************************************************\n\n\n";
	return true;
}

bool AddressBook::printAll()
{
	if (count == 0)
	{
		cout << "               ��ϵ��Ϊ�գ����½���ϵ�ˣ�\n";
		cout << "               ";
		system("pause");
		system("cls");
		return false;
	}
	cout << "               ************************************************************************************\n";
	for (int i = 0; i < count; i++)
		Contact[i].print(1);
	cout << "               ************************************************************************************\n";

	return true;
}

void contact::print()
{
	cout << "               ��ţ�" << Number << "  ������" << Name << "  ��λ��" << Company
		<< "  �绰��" << PhoneNumber << "  ���䣺" << Email << "  ���ࣺ" << Classification << endl;
}

void contact::print(int i)
{
	cout << "               ��ţ�" << Number << "  " << "������" << Name<< endl;
}

void contact::Save(ofstream& save)
{
	save << '*' << Name << '*' << Company << '*' << PhoneNumber
		<< '*' << Email << '*' << Classification << '*';
}

void contact::Edit()
{
	cout << "               �����޸ĺ����Ϣ��\n";
	cout << "               ���Ϊ��" << Number << endl;
	cout << "               ������";
	cin >> Name;
	cout << "               ��λ��";
	cin >> Company;
	cout << "               �绰:";
	cin >> PhoneNumber;
	cout << "               ����:";
	cin >> Email;
	cout << "               ����:";
	cin >> Classification;
}

void contact::add(int n)
{
	cout << "               ����������ϵ�˵���Ϣ��\n";
	Number = n + 1;
	cout << "               ���Ϊ��" << Number << endl;
	cout << "               ������";
	cin >> Name;
	cout << "               ��λ��";
	cin >> Company;
	cout << "               �绰:";
	cin >> PhoneNumber;
	cout << "               ����:";
	cin >> Email;
	cout << "               ����:";
	cin >> Classification;
}

void contact::Delete()
{
	Number = 0;
	Name = "null";
	Company = "null";
	PhoneNumber = "null";
	Email = "null";
	Classification = "null";
	cout << "               ɾ���ɹ���\n";
}

void contact::Read(string Str, int k1, int k2)
{
	int r1 = k1 + 1, r2 = k1 + 1, i = 0;
	while (r2 != (k2 - 1))
	{
		r1 = Str.find('*', r2);
		r2 = Str.find('*', r1 + 1);
		switch (i++)
		{
		case 0:Name.assign(Str, r1 + 1, r2 - r1 - 1); break;
		case 1:Company.assign(Str, r1 + 1, r2 - r1 - 1); break;
		case 2:PhoneNumber.assign(Str, r1 + 1, r2 - r1 - 1); break;
		case 3:Email.assign(Str, r1 + 1, r2 - r1 - 1); break;
		case 4:Classification.assign(Str, r1 + 1, r2 - r1 - 1); break;
		}
	}
}

contact& contact::operator=(contact& C)
{
	this->Name = C.Name;
	this->Company = C.Company;
	this->PhoneNumber = C.PhoneNumber;
	this->Email = C.Email;
	this->Classification = C.Classification;
	return *this;
}
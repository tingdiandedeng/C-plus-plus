#include"head.h"

PerInfo::PerInfo()
{
	string str;
	ifstream read("data1.txt");
	read >> str;
	if (str.length() == 0)
	{
		cout << "               ����ʹ�ã���������ĸ�����Ϣ��\n" << endl;
		Set();
		read.close();
		ofstream Save("data1.txt");
		Save << '*' << name << '*' << age << '*' << height << '*' << weight << '*';
		Save.close();
		cout << "               ��¼�ɹ���\n";
		cout << "               ";
		system("pause");
		system("cls");
		return;
	}
	int p1 = 0, p2, p3, p4, p5;
	p2 = str.find('*', 1);
	p3 = str.find('*', p2 + 1);
	p4 = str.find('*', p3 + 1);
	p5 = str.find('*', p4 + 1);
	string str2, str3, str4;
	name.assign(str, p1 + 1, p2 - p1 - 1);
	str2.assign(str, p2 + 1, p3 - p2 - 1);
	str3.assign(str, p3 + 1, p4 - p3 - 1);
	str4.assign(str, p4 + 1, p5 - p4 - 1);
	age = atof(str2.c_str());
	height = atof(str3.c_str());
	weight = atof(str4.c_str());
	BMI = weight / (height*height);
}
PerInfo::~PerInfo()
{
	ofstream Save("data1.txt");
	Save << '*' << name << '*' << age << '*' << height << '*' << weight << '*';
	Save.close();
}

void PerInfo::Set()
{
	string str;
	cout << "               ������"; cin >> name;
	while (1)
	{
		cout << "               ���䣺"; cin >> str;
		if (!STR(str))
		{
			age = atof(str.c_str()); break;
		}
		else
		{
			cout << "               ������������\n               ";
			system("pause");
			system("cls");
		}
	}
	while (1)
	{
		cout << "               ���(m)��"; cin >> str;
		if (!STR(str))
		{
			height = atof(str.c_str()); break;
		}
		else
		{
			cout << "               ������������\n               ";
			system("pause");
			system("cls");
		}
	}
	while (1)
	{
		cout << "               ����(kg)��"; cin >> str;
		if (!STR(str))
		{
			weight = atof(str.c_str()); break;
		}
		else
		{
			cout << "               ������������\n               ";
			system("pause");
			system("cls");
		}
	}
	BMI = weight / (height*height);
}

void PerInfo::print()
{
	cout << "\n               ��ĸ��˽�����Ϣ����:\n";
	cout << "               ������" << name << endl;
	cout << "               ���䣺" << age << endl;
	cout << "               ���(m)��" << height << endl;
	cout << "               ����(kg)��" << weight << endl;
	cout << "               BMI��" << BMI << endl;
	cout << "               ";
	system("pause");
	system("cls");
}

bool PerInfo::STR(string& str)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (((57 < str[i])||(str[i] < 48))&& (str[i] != 46))
			count++;
	}
	return count;
}

void ThreeBand::setHertRate()
{
	string S;
	time_t t_start, t_end;
	t_start = time(NULL);
	cout << "               �������ַ���¼����(һ���ַ�����һ��)���س���������" << endl;
	cout << "               "; cin >> S;
	t_end = time(NULL);
	double time = difftime(t_end, t_start);
	double count = S.length();
	cout << "               ����������" << count << "   ��ʱ��" << time << "��" << endl;
	double HeartRate = 0;
	HeartRate = count / (time / 60);
	cout << "               ����Ϊ��" << HeartRate << endl;
	P.setHeartRate(HeartRate);
	cout << "               ";
	system("pause");
	system("cls");
}

void ThreeBand::printTime()
{
	time_t t = time(0);
	char tmp[32] = { NULL };
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&t));
	cout << "ʱ�䣺" << tmp;
}

void ThreeBand::setStepNumber()
{
	int i; string str;
	while (1)
	{
		cout << "               1����¼������   0���˳���¼��   2����ʾ��������\n";
		cout << "               "; cin >> i;
		if (i == 1)
		{
			cout << "               �������ַ���¼����(һ���ַ�����һ��)���س���������\n";
			cout << "               "; cin >> str; 
			StepNumber += str.length();
			cout << "               ��¼�ɹ���\n";
			cout << "               ";
			system("pause");
			system("cls");
		}
		else if (i == 0)
		{
			system("cls"); return;
		}
		else if (i == 2)
		{
			cout << "               ��ǰ����Ϊ��" << StepNumber << endl;
			cout << "               ";
			system("pause"); system("cls");
		}
		else
		{
			cout << "               �����������������룡\n"; cout << "               ";
			system("pause");
			system("cls");
		}
	}
}

void ThreeBand::Answer(SmartPhone& S)
{
	if (!S.PhoneRinging())
	{
		cout << "               �绰���ˣ�\n";
		play("7890.wav");
		while (1)
		{
			cout <<"               ���룺 1��������  0���Ҷϡ�\n";
			int i;
			cout << "               "; cin >> i;
			if (i == 1)
			{
				while (1)
				{
					cout << "               ͨ����(0���Ҷϡ�)....\n";
					cout << "               "; cin >> i;
					if (i == 0)
					{
						system("cls");
						return;
					}
					else
					{
						cout << "               �����������������룡\n"; cout << "               ";
						system("pause");
						system("cls");
					}
				}
			}
			else if (i == 0)
			{
				cout << "               ";
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "               �����������������룡\n"; cout << "               ";
				system("pause");
				system("cls");
				cout << "               �绰���ˣ�\n";
			}
		}
	}
	return;
}

void ThreeBand::call(SmartPhone& S)
{
	string str;
	cout << "               ����绰���룺";
	cin >> str;
	cout << "               ���ڲ���" << str << endl;
	play("1670.wav");
	if (S.call(str))
	{
		while (1) {
			cout << "               ͨ����....\n               ����0�Ҷϣ�";
			int i;
			cin >> i;
			if (i == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "               �����������������룡\n"; cout << "               ";
				system("pause");
				system("cls");
			}
		}
	}
	else
	{
		cout << "               ��ʱ���˽���...\n";
		play("356.wav");
	}
	system("cls");
	return;
}

void ThreeBand::call(SmartPhone& S, string name, string PhoneNumber)
{
	cout << "               ���ڲ���" << name << "  " << PhoneNumber << endl;
	play("1670.wav");
	if (S.call(PhoneNumber))
	{
		while (1) {
			cout << "               ͨ����....\n               ����0�Ҷϣ�";
			int i;
			cin >> i;
			if (i == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "               �����������������룡\n"; cout << "               ";
				system("pause");
				system("cls");
			}
		}
	}
	else
	{
		cout << "               ��ʱ���˽���...\n";
		play("356.wav");
	}
	system("cls");
	return;
}

void ThreeBand::addressBook(SmartPhone& S)
{
	AddressBook& B = S.getBook();
	int flag = -1;
	while (1)
	{
		cout << "               ����  1���½���ϵ�ˡ�  2����ʾ������ϵ�ˡ�  0���˳��� \n";
		cout << "               "; cin >> flag;
		if (flag == 0)
		{
			cout << "               ";
			system("cls");
			return;
		}
		else if (flag == 1)
		{
			system("cls");
			B.Add();
			cout << "               �½��ɹ���\n";
			cout << "               ";
			system("pause");
			system("cls");
		}
		else if (flag == 2)
		{
			system("cls");
			if (!B.printAll())
				continue;
			while (1)
			{
				if (!B.empty())
					break;
				cout << "               �������Բ鿴��ϵ��(0��������һ�㡿)��\n";
				cout << "               "; cin >> flag;
				if (flag != 0)
				{
					system("cls");
					if (!B.print(flag))
					{
						B.printAll();
						continue;
					}
					while (1)
					{
						int f;
						cout << "               ����  1���༭��  2��ɾ����  3�����绰��  0�����ء�  -1���ر�ͨѶ¼��\n";
						cout << "               "; cin >> f;
						if (f == 2)
						{
							B.Delete(flag);
							cout << "               ";
							system("pause");
							system("cls");
							B.printAll();
							break;
						}
						else if (f == 1)
						{
							B.Edit(flag);
							cout << "               �޸ĳɹ���\n";
							cout << "               ";
							system("pause");
							system("cls");
							B.printAll();
							break;
						}
						else if (f == 3)
						{
							system("cls"); call(S, B.getName(flag), B.getPhoneNumber(flag));
							system("cls");
							B.printAll();
							break;
						}
						else if (f == 0)
						{
							system("cls"); B.printAll(); break;
						}
						else if (f == -1)
						{
							system("cls"); return;
						}
						else
						{
							cout << "               �����������������룡\n"; cout << "               ";
							system("pause");
							system("cls");
							B.print(flag);
						}
					}
				}
				else
				{
					flag = -1;
					system("cls");
					break;
				}
			}
		}
		else
		{
			cout << "               �����������������룡\n"; cout << "               ";
			system("pause");
			system("cls");
		}
	}
}

bool SmartPhone::call(string n)
{
	srand((unsigned)time(NULL));
	return rand() % (2) + 0;
}
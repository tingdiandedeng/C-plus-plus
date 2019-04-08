#include"head.h"

PerInfo::PerInfo()
{
	string str;
	ifstream read("data1.txt");
	read >> str;
	if (str.length() == 0)
	{
		cout << "               初次使用，请输入你的个人信息！\n" << endl;
		Set();
		read.close();
		ofstream Save("data1.txt");
		Save << '*' << name << '*' << age << '*' << height << '*' << weight << '*';
		Save.close();
		cout << "               记录成功！\n";
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
	cout << "               姓名："; cin >> name;
	while (1)
	{
		cout << "               年龄："; cin >> str;
		if (!STR(str))
		{
			age = atof(str.c_str()); break;
		}
		else
		{
			cout << "               请输入整数！\n               ";
			system("pause");
			system("cls");
		}
	}
	while (1)
	{
		cout << "               身高(m)："; cin >> str;
		if (!STR(str))
		{
			height = atof(str.c_str()); break;
		}
		else
		{
			cout << "               请输入整数！\n               ";
			system("pause");
			system("cls");
		}
	}
	while (1)
	{
		cout << "               体重(kg)："; cin >> str;
		if (!STR(str))
		{
			weight = atof(str.c_str()); break;
		}
		else
		{
			cout << "               请输入整数！\n               ";
			system("pause");
			system("cls");
		}
	}
	BMI = weight / (height*height);
}

void PerInfo::print()
{
	cout << "\n               你的个人健康信息如下:\n";
	cout << "               姓名：" << name << endl;
	cout << "               年龄：" << age << endl;
	cout << "               身高(m)：" << height << endl;
	cout << "               体重(kg)：" << weight << endl;
	cout << "               BMI：" << BMI << endl;
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
	cout << "               按任意字符记录心跳(一个字符代表一次)，回车键结束：" << endl;
	cout << "               "; cin >> S;
	t_end = time(NULL);
	double time = difftime(t_end, t_start);
	double count = S.length();
	cout << "               心跳次数：" << count << "   用时：" << time << "秒" << endl;
	double HeartRate = 0;
	HeartRate = count / (time / 60);
	cout << "               心率为：" << HeartRate << endl;
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
	cout << "时间：" << tmp;
}

void ThreeBand::setStepNumber()
{
	int i; string str;
	while (1)
	{
		cout << "               1【记录步数】   0【退出记录】   2【显示步数】：\n";
		cout << "               "; cin >> i;
		if (i == 1)
		{
			cout << "               按任意字符记录步数(一个字符代表一次)，回车键结束：\n";
			cout << "               "; cin >> str; 
			StepNumber += str.length();
			cout << "               记录成功！\n";
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
			cout << "               当前步数为：" << StepNumber << endl;
			cout << "               ";
			system("pause"); system("cls");
		}
		else
		{
			cout << "               输入有误，请重新输入！\n"; cout << "               ";
			system("pause");
			system("cls");
		}
	}
}

void ThreeBand::Answer(SmartPhone& S)
{
	if (!S.PhoneRinging())
	{
		cout << "               电话来了！\n";
		play("7890.wav");
		while (1)
		{
			cout <<"               输入： 1【接听】  0【挂断】\n";
			int i;
			cout << "               "; cin >> i;
			if (i == 1)
			{
				while (1)
				{
					cout << "               通话中(0【挂断】)....\n";
					cout << "               "; cin >> i;
					if (i == 0)
					{
						system("cls");
						return;
					}
					else
					{
						cout << "               输入有误，请重新输入！\n"; cout << "               ";
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
				cout << "               输入有误，请重新输入！\n"; cout << "               ";
				system("pause");
				system("cls");
				cout << "               电话来了！\n";
			}
		}
	}
	return;
}

void ThreeBand::call(SmartPhone& S)
{
	string str;
	cout << "               输入电话号码：";
	cin >> str;
	cout << "               正在播打：" << str << endl;
	play("1670.wav");
	if (S.call(str))
	{
		while (1) {
			cout << "               通话中....\n               输入0挂断：";
			int i;
			cin >> i;
			if (i == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "               输入有误，请重新输入！\n"; cout << "               ";
				system("pause");
				system("cls");
			}
		}
	}
	else
	{
		cout << "               暂时无人接听...\n";
		play("356.wav");
	}
	system("cls");
	return;
}

void ThreeBand::call(SmartPhone& S, string name, string PhoneNumber)
{
	cout << "               正在播打：" << name << "  " << PhoneNumber << endl;
	play("1670.wav");
	if (S.call(PhoneNumber))
	{
		while (1) {
			cout << "               通话中....\n               输入0挂断：";
			int i;
			cin >> i;
			if (i == 0)
			{
				system("cls");
				return;
			}
			else
			{
				cout << "               输入有误，请重新输入！\n"; cout << "               ";
				system("pause");
				system("cls");
			}
		}
	}
	else
	{
		cout << "               暂时无人接听...\n";
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
		cout << "               输入  1【新建联系人】  2【显示所有联系人】  0【退出】 \n";
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
			cout << "               新建成功！\n";
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
				cout << "               输入编号以查看联系人(0【返回上一层】)：\n";
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
						cout << "               输入  1【编辑】  2【删除】  3【拨电话】  0【返回】  -1【关闭通讯录】\n";
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
							cout << "               修改成功！\n";
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
							cout << "               输入有误，请重新输入！\n"; cout << "               ";
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
			cout << "               输入有误，请重新输入！\n"; cout << "               ";
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
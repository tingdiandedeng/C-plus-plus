#include"head.h"

int main()
{
	ThreeBand B; SmartPhone S; int i;
	while (1)
	{
		cout << "               ************************************************************************************\n";
		cout << "               *                                                       "; B.printTime(); cout << "  *\n";
		cout << "               *                                                                                  *\n";
		cout << "               *  1【测心率】  2【计步】  3【显示健康信息】  4【拨打电话】  5【通讯录】  0【退出】*\n";
		cout << "               ************************************************************************************\n";
		cout << "\n               输入你想执行的操作:"; cin >> i;
		switch (i)
		{
		case 1:B.setHertRate(); break;
		case 2:B.setStepNumber(); break;
		case 3:B.printPerInfo(); break;
		case 4:B.call(S); break;
		case 5:B.addressBook(S); break;
		case 0:cout << "               "; return 0;
		default:cout << "               输入有误，请重新输入！\n"; cout << "               ";
			system("pause");
			system("cls");
		}
		B.Answer(S);
	}
	return 0;
}
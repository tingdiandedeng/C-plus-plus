#include"head.h"

int main()
{
	ThreeBand B; SmartPhone S; int i;
	while (1)
	{
		cout << "               ************************************************************************************\n";
		cout << "               *                                                       "; B.printTime(); cout << "  *\n";
		cout << "               *                                                                                  *\n";
		cout << "               *  1�������ʡ�  2���Ʋ���  3����ʾ������Ϣ��  4������绰��  5��ͨѶ¼��  0���˳���*\n";
		cout << "               ************************************************************************************\n";
		cout << "\n               ��������ִ�еĲ���:"; cin >> i;
		switch (i)
		{
		case 1:B.setHertRate(); break;
		case 2:B.setStepNumber(); break;
		case 3:B.printPerInfo(); break;
		case 4:B.call(S); break;
		case 5:B.addressBook(S); break;
		case 0:cout << "               "; return 0;
		default:cout << "               �����������������룡\n"; cout << "               ";
			system("pause");
			system("cls");
		}
		B.Answer(S);
	}
	return 0;
}
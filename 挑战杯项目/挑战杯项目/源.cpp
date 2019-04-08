#include"head.h"

double EARTH_RADIUS = 6378.137;
double PI = 3.141592653;
double rad(double d)
{
	return (d * PI) / 180.0;
}
double GetDistance(Location L1, Location L2)
{
	double radLat1 = rad(L1.GetX());
	double radLat2 = rad(L2.GetX());
	double a = radLat1 - radLat2;
	double b = rad(L1.GetY()) - rad(L2.GetY());
	double DIStance = 2 * asin(sqrt(pow(sin(a / 2), 2) +
		cos(radLat1)*cos(radLat2)*pow(sin(b / 2), 2)));
	DIStance = DIStance * EARTH_RADIUS;
	DIStance = round(DIStance * 10000) / 10000;
	return DIStance;

}

float GetTime(Location L1, Location L2, int NumberOfPeople)
{
	if (NumberOfPeople > 600)
		return ((GetDistance(L1, L2) / 0.09) + (NumberOfPeople - 600) / 4);
	else
		return (GetDistance(L1, L2) / 0.09);
}

bool PrintIntroduction(Person P, Scene s[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (GetDistance(P.GetNow(), s[i].GetLocation()) < 0.005)
		{
			cout << "���ѵ��� " << s[i].GetName() << "\n��飺" << s[i].GetIntroduction() << endl;
			return 1;
			s[i].SetNumberOfPeople();
		}
	}
	return 0;
}

Scene* BestPath(Person P, Scene* s, int count)
{
	int i;
	for (i = 0; i<count; i++)
		if (GetDistance(P.GetDestination(), (*(s + i)).GetLocation()) < 0.005)
		{
			Scene temp1 = *(s + i);
			*(s + i) = *(s + count - 1);
			*(s + count - 1) = temp1;
		}
	for (i = 0; i + 1 < count; i++)
	{
		for (int j = count - 2; j > i + 1; j--)
		{
			if (i == 0)
			{
				if (GetTime(P.GetNow(), (*(s + j)).GetLocation(), (*(s + j)).GetNumberOfPeople())
					< GetTime(P.GetNow(), (*(s + j - 1)).GetLocation(), (*(s + j - 1)).GetNumberOfPeople()))
				{
					Scene temp2 = *(s + j);
					*(s + j) = *(s + j - 1);
					*(s + j - 1) = temp2;
				}
			}
			else
			{
				if (GetTime((*(s + i)).GetLocation(), (*(s + j)).GetLocation(), (*(s + j)).GetNumberOfPeople())
					< GetTime((*(s + i)).GetLocation(), (*(s + j - 1)).GetLocation(), (*(s + j - 1)).GetNumberOfPeople()))
				{
					Scene temp3 = *(s + j);
					*(s + j) = *(s + j - 1);
					*(s + j - 1) = temp3;
				}
			}
		}
	}
	return s;
}

int main()
{
	Scene S[7] = {
		Scene("�Ჴ����", 31.1875331338204, 121.494452010447, "�Ჴ�����ҹݵ������ǡ��ӵ������ǵĹ��¡���Ѱ�ҳ��е���ꣻ̽����˼��������ȡ�˼ӵ���������ǧ������ʷ����Ϊ�������������Ļ����ĵļ����Ի�ʱ�̣�ͨ��������ʽ���ݱ���չ�ֳ��еķ�չ�����š�", 500),
		Scene("ӡ�ȹ�",31.1875331338204,121.494452010447,"�Ჴ�����ҹݵ������ǡ��ӵ������ǵĹ��¡���Ѱ�ҳ��е���ꣻ̽����˼��������ȡ�˼ӵ���������ǧ������ʷ����Ϊ�������������Ļ����ĵļ����Ի�ʱ�̣�ͨ��������ʽ���ݱ���չ�ֳ��еķ�չ�����š��Ჴ��չ�ݽ��ص�ͻ�������ڻ�������������Դ����ɫ��������������Ŭ����",543),
		Scene("ɳ�ذ�������",31.1888134941069,121.495868216504,"ɳ�ذ�����չ�ݵĻ��������������6000ƽ���ף�������Ϊ�������Ļ���������չ�ֶ�ɳ�ذ�������������ͷ�չ�Լ��Ե��ؾ�����������޴�Ӱ��������ģ���2010�Ϻ������ᡰ���У�����������á������������ϡ�",650),
		Scene("������",31.1893550032817,121.496764074315,"���ģ���Ϊ����������ķ���֮һ����ֱ��������չ�ݵ�������֮�У��������еļ�������Ҳ�ڽ����ϵõ��������͡��ο��ǿ������Ϻ���̤�ϡ��׶������أ�չ��һ�������С�����ٱ��ĺ����׶��׶����Ļ������ԡ��Ƽ�����Ȼ��Щ�����ĳ�����Ϣ���ڶ��㣬ͨ�����ָ߿Ƽ����ֶ����������ο��ǿ������ֺ������еĸ���ͼ����������ʳ���������������ֵȡ�2012�����ˮ�����ᣬ����������ǰչ�֡�������δ���ġ�I Ocean�����֣��οͿ��Կ������󻯵ġ����ˡ����˽���ˮ������ĺ������⡣",800),
		Scene("�ձ���",31.1907546524732,121.497917424192,"�ձ����ҹݵĲ�չ����Ϊ����֮�ͣ���֮�͡���չ�ݸ�Լ24�ף�ռ��6000ƽ���ס�չ������ϣ������˻������Ƽ�����չ���ⲿ���ɷ���ĳ����ͱ�Ĥ����Χ����չ���ڽ���ʹ��ѭ��ʽ�����׵������µļ���������Ϻ���������ձ����ҹݼ̳���2005�갮֪�����ᡰ����Ȼ���������������������չʾһ����ʵ���ձ��Ϳɳ�����չ��21�������͵ĳ����������̬��",953),
		Scene("�ͻ�˹̹��",31.1855797482633,121.495968467007,"�ͻ�˹̹���ҹ��������й��ݵ����棬����չ�ݽ�һ��֮ң�����Դ���ڰͻ�˹̹���������϶��ű��������ű�ʼ����1025�꣬����1566�꾭���������ֳ����ڵ���ò�����϶��ǰͻ�˹̹���Ļ����ģ����϶��ű����佨��֮���ͼ�֤����ʷ�ı�Ǩ��Ҳ��Ϊ��������м����������ĵر꣬���������������Ĺű��ѱ��������Ϲ��̿�����֯�������Ų���¼���ͻ�˹̹ӵ�н�5000��Ĺ�������ʷ����������ʷ���ǲ�ʤö�١�",562),
		Scene("�й���",31.1844186657722,121.494428879032,"�Ϻ��������й����ҹݽ�������ԡ�����֮�ڡ��Ĺ�˼���⣬����й��Ļ��ľ��������ʡ����ҹݾ������𡢲����������Ϊ�����й�Ԫ�ء������й�����ĵ��ܸ��������塪������֮�ڣ�������ˮƽչ��������չ��ƽ̨��������̬ӳ�Ĺ��ҹݣ���Ϊ���š����ԡ����񡢲�ηḻ�ĳ��й㳡�����߻�Ϊ���̡����ಹ�䣬��ͬ��ɱ��ʢ����������ͳһ���塣���ҹݡ������ݹ������·���������������ϣ��ռ����ϱ�������ͳ�죬�γ�׳�۵ĳ��пռ����У��γɶ�һ�޶��ı�־�Խ���Ⱥ�塣",1200)
	};
	Person P(31.1884387958194, 121.499814754734);
	P.SetDestination(31.1875331338204, 121.494452010447);
	P.SetNow(31.1844186657722, 121.494428879032);
	PrintIntroduction(P, S, 7);
	cout << "\n\n";
	P.SetNow(31.1884387958194, 121.499814754734);
	BestPath(P, S, 7);
	cout << "����Ŀ�ĵ�Ϊ��" << S[6].GetName() << endl;
	cout << "Ϊ�������Ƽ�·��Ϊ����ǰλ�á�";
	float SumTime = 0;
	float SumDistance = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			SumTime += GetTime(P.GetNow(), S[i].GetLocation(), S[i].GetNumberOfPeople());
			SumDistance += GetDistance(P.GetNow(), S[i].GetLocation());
		}
		else
		{
			SumTime += GetTime(S[i - 1].GetLocation(), S[i].GetLocation(), S[i].GetNumberOfPeople());
			SumDistance += GetDistance(S[i - 1].GetLocation(), S[i].GetLocation());
		}
		cout << S[i].GetName();
		if (i != 6)
			cout << "��";
	}
	cout << endl;
	cout << "�ܾ��룺" << SumDistance << "km\n";
	int hours = SumTime / 60; int mins = SumTime - hours * 60;
	cout << "Ԥ�ƺ�ʱ��" << hours << "h" << mins << "min\n";
	system("pause");
	return 0;
}
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
			cout << "您已到达 " << s[i].GetName() << "\n简介：" << s[i].GetIntroduction() << endl;
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
		Scene("尼泊尔馆", 31.1875331338204, 121.494452010447, "尼泊尔国家馆的主题是“加德满都城的故事——寻找城市的灵魂；探索与思考”，截取了加德满都在两千余年历史上作为建筑、艺术、文化中心的几个辉煌时刻，通过建筑形式的演变来展现城市的发展与扩张。", 500),
		Scene("印度馆",31.1875331338204,121.494452010447,"尼泊尔国家馆的主题是“加德满都城的故事——寻找城市的灵魂；探索与思考”，截取了加德满都在两千余年历史上作为建筑、艺术、文化中心的几个辉煌时刻，通过建筑形式的演变来展现城市的发展与扩张。尼泊尔展馆将重点突出本国在环保、可再生能源，绿色建筑方面所做的努力。",543),
		Scene("沙特阿拉伯馆",31.1888134941069,121.495868216504,"沙特阿拉伯展馆的划定区域总面积达6000平方米，其主题为“生命的活力”，将展现对沙特阿拉伯城市崛起和发展以及对当地居民生活产生巨大影响的五大核心，与2010上海世博会“城市，让生活更美好”的主题相契合。",650),
		Scene("韩国馆",31.1893550032817,121.496764074315,"韩文，作为韩国最优秀的发明之一，被直接体现在展馆的外观设计之中，韩文特有的几何特征也在建筑上得到完美阐释。游客们可以在上海“踏上”首尔的土地，展馆一层就是缩小了三百倍的韩国首都首尔；文化、人性、科技、自然这些韩国的城市信息将在二层，通过各种高科技的手段演绎，在这里，游客们可以体现韩国城市的各个图景，包括韩食、韩服、韩国音乐等。2012年的丽水世博会，将在这里提前展现。在描述未来的“I Ocean”部分，游客可以看到形象化的“海浪”，了解丽水世博会的海洋主题。",800),
		Scene("日本馆",31.1907546524732,121.497917424192,"日本国家馆的参展主题为“心之和，技之和”。展馆高约24米，占地6000平方米。展馆设计上，采用了环境控制技术。展馆外部被可发电的超轻型薄膜所包围，而展馆内将会使用循环式呼吸孔道等最新的技术。这次上海世博会的日本国家馆继承了2005年爱知世博会“与自然共生”的理念。期望向世界展示一个真实的日本和可持续发展的21世纪新型的城市生活的形态。",953),
		Scene("巴基斯坦馆",31.1855797482633,121.495968467007,"巴基斯坦国家馆坐落于中国馆的西面，两国展馆仅一步之遥，设计源自于巴基斯坦著名的拉合尔古堡，这座古堡始建于1025年，又在1566年经历改造后呈现出现在的面貌。拉合尔是巴基斯坦的文化中心，拉合尔古堡从其建立之初就见证了历史的变迁，也成为了这个城市极具象征力的地标，这座美丽而著名的古堡已被列入联合国教科文组织的世界遗产名录。巴基斯坦拥有近5000年的古文明历史，著名的历史名城不胜枚举。",562),
		Scene("中国馆",31.1844186657722,121.494428879032,"上海世博会中国国家馆建筑外观以“东方之冠”的构思主题，表达中国文化的精神与气质。国家馆居中升起、层叠出挑，成为凝聚中国元素、象征中国精神的雕塑感造型主体——东方之冠；地区馆水平展开，以舒展的平台基座的形态映衬国家馆，成为开放、柔性、亲民、层次丰富的城市广场；二者互为对仗、互相补充，共同组成表达盛世大国主题的统一整体。国家馆、地区馆功能上下分区、造型主从配合，空间以南北向主轴统领，形成壮观的城市空间序列，形成独一无二的标志性建筑群体。",1200)
	};
	Person P(31.1884387958194, 121.499814754734);
	P.SetDestination(31.1875331338204, 121.494452010447);
	P.SetNow(31.1844186657722, 121.494428879032);
	PrintIntroduction(P, S, 7);
	cout << "\n\n";
	P.SetNow(31.1884387958194, 121.499814754734);
	BestPath(P, S, 7);
	cout << "您的目的地为：" << S[6].GetName() << endl;
	cout << "为你智能推荐路线为：当前位置→";
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
			cout << "→";
	}
	cout << endl;
	cout << "总距离：" << SumDistance << "km\n";
	int hours = SumTime / 60; int mins = SumTime - hours * 60;
	cout << "预计耗时：" << hours << "h" << mins << "min\n";
	system("pause");
	return 0;
}
#include<iostream>

using namespace std;

float L(float x, float* xi, int n, int k,int j)
{
	float A = 1; float B = 1;
	int i; int a = k;
	for (i = 0; i <= n; i++,a++)
	{
		if (j == a)
			continue;
		else
		{
			A *= x - xi[a];
			B *= xi[j] - xi[a];
		}
	}
	return A / B;
}

float F(float x,float* xi,float* yi,int n,int k)
{
	float A = 0; int j = k;
	for (int i = 0; i <= n; i++, j++)
		A += yi[j] * L(x, xi, n, k, j);
	return A;
}


int main()
{
	int i, j;
	/*float ti[15] = { 1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8 };
	float yi[15] = { 33.4,79.5,122.65,159.05,189.15,214.15,238.65,252.2,267.55,280.5,296.65,301.65,310.4,318.15,325.15 };
	float Y[13][15];
	for(j=0;j<13;j++)
		for (i = 0; i < 15; i++)
			Y[j][i] = F(ti[i], ti, yi, 3,j);
	for (j = 0; j < 13; j++)
		{
		for (i = 0; i < 15; i++)
		{
			cout << Y[j][i];
			if (i < 14)
				cout << ",";
		}
			cout << endl;
		}*/
	float ti[] = { 1,4,8 };
	float yi[] = { 33.4,238.65,325.15 };
	float Y[15];
	for (i = 0; i < 15; i++)
		Y[i] = F(1+i*0.5, ti, yi, 2, 0);
	for (i = 0; i < 15; i++)
	{
		cout << Y[i];
		if (i < 14)
			cout << ",";
	}
	cout << endl;
	system("pause");
	return 0;
}
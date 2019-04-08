#include<iostream>
#include<cmath>
#define N 3

using namespace std;

void Jacobi(double *X,double *x,double **A, double *B,int n)
{
	for (int i = 1; i <= n; i++)
	{
		int j; double sum=0;
		for (j = 1; j <= n; j++)
		{
			if (j != i)
				sum += A[i][j] * x[j];
		}
		X[i] = (B[i] - sum) / A[i][i];
	}
}

void Gauss(double *X, double *Y, double **A, double *B)
{
	for (int i = 1; i <= N; i++)
	{
		double sum1 = 0, sum2 = 0;int j;
		for (j = 1; j <= i - 1; j++)
			sum1 += A[i][j]*X[j];
		for (j = i + 1; j <= N; j++)
			sum2 += A[i][j] * Y[j];
		X[i] = (B[i] - sum1 - sum2) / A[i][i];
	}
}

void SOR(double *X, double *Y, double **A, double *B, double w)
{
	for (int i = 1; i <= N; i++)
	{
		double sum1 = 0, sum2 = 0; int j;
		for (j = 1; j <= i - 1; j++)
			sum1 += A[i][j] * X[j];
		for (j = i; j <= N; j++)
			sum2 += A[i][j] * Y[j];
		X[i] = Y[i]+w*(B[i] - sum1 - sum2) / A[i][i];
	}
}

int main()
{
	int i; int j;
	double x[N+1] = { 0,0,0 };
	double a[N][N] = { {10,-1,-2},{-1,10,-2},{-1,-1,5} };
	double *X1 = new double[N+1];
	for (i = 1; i <= N; i++)
		X1[i] = x[i - 1];
	double *X2 = new double[N + 1];
	double B[N+1] = {0,72,83,42 };
	double **A = new double*[N+1];
	for (i = 0; i <= N; i++)
		A[i] = new double[N+1];
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			A[i][j]=a[i-1][j-1];
	i = 0; double x1, x2, x3;
	do
	{
		if (i % 2 == 0)
		{
			x1 = (X1[1]+X1[2]+X1[3])/3;
			Jacobi(X2, X1, A, B, 3);
			x2 = (X2[1]+ X2[2]+ X2[3])/3;
			x3= ((X2[1]-11)+ (X2[2]-12) + (X2[3]-13)) / 3;
			cout << "雅可比迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X2[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
		else if(i%2==1)
		{
			x1 = (X2[1] + X2[2] + X2[3]) / 3;
			Jacobi(X1, X2, A, B, 3);
			x2 = (X1[1] + X1[2] + X1[3]) / 3;
			x3 = ((X1[1] - 11) + (X1[2] - 12) + (X1[3] - 13)) / 3;
			cout << "雅可比迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X1[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
		
	} while (abs(x3) > 0.0025);
	system("pause");
	system("cls");//雅可比算法

	for (i = 1; i <= N; i++)
		X1[i] = x[i - 1];
	i = 0;
	do 
	{
		if (i % 2 == 0)
		{
			x1 = (X1[1] + X1[2] + X1[3]) / 3;
			Gauss(X2, X1, A, B);
			x2 = (X2[1] + X2[2] + X2[3]) / 3;
			x3 = ((X2[1] - 11) + (X2[2] - 12) + (X2[3] - 13)) / 3;
			cout << "高斯赛德尔迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X2[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
		else if (i % 2 == 1)
		{
			x1 = (X2[1] + X2[2] + X2[3]) / 3;
			Gauss(X1, X2, A, B);
			x2 = (X1[1] + X1[2] + X1[3]) / 3;
			x3 = ((X1[1] - 11) + (X1[2] - 12) + (X1[3] - 13)) / 3;
			cout << "高斯赛德尔迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X1[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
	} while (abs(x3) > 0.0025);
	system("pause");
	system("cls");//高斯赛德尔迭代算法

	for (i = 1; i <= N; i++)
		X1[i] = x[i - 1];
	i = 0;
	double w = 1.05;//松弛因子
	do
	{
		if (i % 2 == 0)
		{
			x1 = (X1[1] + X1[2] + X1[3]) / 3;
			SOR(X2, X1, A, B,w);
			x2 = (X2[1] + X2[2] + X2[3]) / 3;
			x3 = ((X2[1] - 11) + (X2[2] - 12) + (X2[3] - 13)) / 3;
			cout << "超松弛迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X2[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
		else if (i % 2 == 1)
		{
			x1 = (X2[1] + X2[2] + X2[3]) / 3;
			SOR(X1, X2, A, B,w);
			x2 = (X1[1] + X1[2] + X1[3]) / 3;
			x3 = ((X1[1] - 11) + (X1[2] - 12) + (X1[3] - 13)) / 3;
			cout << "超松弛迭代" << ++i << "次后的X向量为：\n{";
			for (j = 1; j <= N; j++)
			{
				cout << X1[j];
				if (j != N)
					cout << ",";
			}
			cout << "}\n";
		}
	} while (abs(x3) > 0.0025);//超松弛迭代算法

	for (i = 0; i <= N; i++)
		delete[]A[i];
	delete[]A;
	delete[]X1;
	delete[]X2;
	system("pause");
	return 0;
}
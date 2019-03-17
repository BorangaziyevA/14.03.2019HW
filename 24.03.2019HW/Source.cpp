#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>

using namespace std;

void Fill(int **p, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			p[i][j] = 1 + rand() % 10;
		}

		
	}

}

void Print(int **p, int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << p[i][j] << " ";

		}
		cout << endl;
	}
}

void Stolb(int **&p, int n,int &m, int k)
{
	int **tmp;
	tmp = new int*[n];
	int flag = 0;
	for (size_t i = 0; i < n; i++)
	{
		tmp[i] = new int[m + 1];
	}
	for (size_t i = 0; i < n; i++)
	{
		flag = 0;
		for (size_t j = 0; j < m; j++)
		{
			if (j == k)
			{
				flag = 1;
			}
			if (flag == 1)
			{
				tmp[i][j+1] = p[i][j];
			}
			else 
				tmp[i][j] = p[i][j];
		}

	}
	for (size_t i = 0; i < n; i++)
	{
		tmp[i][k] = 0;
	}

	delete[] p;

	p = tmp;

	m++;

}

void sum(int **ppp, int n, int m, int **pp, int **p)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			ppp[i][j] = pp[i][j] + p[i][j];
		}
	}
}

/////////////2/2/2/2/2/
int main()
{
	srand(time(NULL));

	int n, m;
	cin >> n >> m;

	int **p;
	int **pp, **ppp;
	p = new int*[n];
	pp = new int*[n];
	ppp = new int*[n];

	for (size_t i = 0; i < n; i++)
	{
		p[i] = new int[m];
	}
	for (size_t i = 0; i < n; i++)
	{
		pp[i] = new int[m];
	}
	for (size_t i = 0; i < n; i++)
	{
		ppp[i] = new int[m];
	}

	Fill(p, n, m);
	Print(p, n, m);
	cout <<endl << "+++++++++++++++++++++"<< endl << endl;
	Fill(pp, n, m);
	Print(pp, n, m);
	cout << endl << "=====================" << endl << endl;
	sum(ppp, n, m, pp, p);
	Print(ppp, n, m);

	for (size_t i = 0; i < n; i++)
	{
		delete[] p[i];
	}

	delete[] p;

	for (size_t i = 0; i < n; i++)
	{
		delete[] pp[i];
	}

	delete[] pp;

	for (size_t i = 0; i < n; i++)
	{
		delete[] ppp[i];
	}

	delete[] ppp;

	system("pause");
	return 0;
}


////////1/////1////1////1/
///int main()
//{
//	srand(time(NULL));
//
//	int n, m;
//	cin >> n >> m;
//
//	int **p;
//	p = new int*[n];
//
//	for (size_t i = 0; i < n; i++)
//	{
//		p[i] = new int[m];
//	}
//
//	int k;
//	cout << "New column" << endl;
//	cin >> k;
//
//	Fill(p, n, m);
//	Print(p, n, m);
//	cout << endl << endl;
//	Stolb(p, n, m,k);
//	Print(p, n, m);
//
//	for (size_t i = 0; i < n; i++)
//	{
//		delete[] p[i];
//	}
//
//	delete[] p;
//
//
//	system("pause");
//	return 0;
//}
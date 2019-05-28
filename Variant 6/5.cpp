
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


int main() {
	srand(time(NULL));
	int n, m;
	cout << "Enter n & m : " << endl;
	cin >> n >> m; 

	char **a = new char*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new char[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < m; r++)
		{
			cout << a[i][r] << " ";
			cin>>a[i][r];
		}
		cout << endl;
	}
	int counter = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < m; r++)
		{
			for (int t = 0; t < n; t++)
			{
				for (int h = 0; h < m; h++)
				{
					if (a[i][r] == a[t][h] && t != i && r != h) { 
						a[t][h] = '5';                    
					}
				}
			}
		}
	}
	

	for (int i = 0; i < n; i++) 
	{
		for (int r = 0; r < m; r++)
		{
			if (a[i][r] != '5') {
				counter++;
			}
		}
		cout << endl;
	}

	cout << "The number of elements is: " << counter << endl;
	system("pause");
	return 0;
}

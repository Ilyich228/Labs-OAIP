
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;





int main()
{
	srand(time(NULL));
	int m, n;
	cout << "Enter the size of matrix MxN" << endl;
	cin >> m >> n;

	int **matrix = new int*[m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 500;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl; cout << endl; cout << endl;
	//
	bool exit = true;
	for (int i = 0; i < m; i++)
	{
		exit = true;
		for (int j = 0; j < n-1; j++)
		{
			if (matrix[j][i] > matrix[j+1][i]) {
				exit = false;			
			}
			cout << matrix[i][j] << " ";
			if (j == n - 2) { cout << matrix[i][n-1]; }
		}
		if (exit == true) {
			cout << "	0";
		}
		else {
			cout << "	1";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
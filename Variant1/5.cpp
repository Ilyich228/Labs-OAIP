#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double **mat;
	int n, m;
	cin >> n >> m;

	mat = new double*[n];

	for (int i = 0; i < n; i++)
	{
		mat[i] = new double[m];

		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	//qsort(mat, n, sizeof(double*), compare);



	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << " ";
		}

		cout << endl;
	}


	for (int i = 0; i < n; i++)
		delete[] mat[i];

	delete[] mat;

	return 0;
}
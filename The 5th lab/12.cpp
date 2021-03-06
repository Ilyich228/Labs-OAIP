#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


int main() {
	srand(time(NULL));
	int n;
	cout << "Enter n" << endl;
	cin >> n; 

	int **a = new int*[n]; 
	for (int i = 0; i < n; i++) 
	{
		a[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < n; r++)
		{
			a[i][r] = rand()%21 + 10; 
			cout << a[i][r] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		int max = 0;
		int max_index = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max) {
				max = a[i][j];
				max_index = j;
			}
		}
		//cout << endl << endl << a[i][max_index] << endl;
		swap(a[i][max_index], a[i][i]);
	}

	int *bb = new int[n];
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		bb[i] = a[i][i];
		cout << bb[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < n-1; i++)
	{
		if (bb[i] > bb[i + 1]) {
			swap(a[i], a[i + 1]);
			swap(bb[i], bb[i + 1]);
			i = -1;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < n; r++)
		{
			cout << a[i][r] << " ";			 
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
//48-57
int main() 
{
	srand(time(NULL));

	cout << "Enter k" << endl;
	int k;
	cin >> k;
	char *ptrAr = new char[k];

	for (int i = 0; i < k; i++)
	{
		ptrAr[i] = rand() % 128;
		cout << ptrAr[i] << " ";
	}
	cout << endl;

	int numbers_size = 0, other_size = 0;
	char *ptrNumbers = new char[numbers_size];
	char *ptrOther = new char[other_size];

	int counter_num = 0, counter_other = 0;
	for (int i = 0; i < k; i++)
	{
		if (ptrAr[i] >= 48 && ptrAr[i] <= 57)
		{
			ptrNumbers[counter_num] = ptrAr[i];
			counter_num++;
			numbers_size++;
		}
		else 
		{
			ptrOther[counter_other] = ptrAr[i];
			counter_other++;
			other_size++;
		}
	}

	cout << endl;

	for (int i = 0; i < numbers_size; i++)
	{
		cout << ptrNumbers[i] << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < other_size; i++)
	{
		cout << ptrOther[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
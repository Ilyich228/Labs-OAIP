﻿#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;


int main() {
	srand(time(NULL));
	int n, m;
	cout << "Enter n & m : " << endl;
	cin >> n >> m; //Ввели размерность матрицы

	char **a = new char*[n]; //Создали указатель на указатель бла бла хуй знает просто всегда так писал
	for (int i = 0; i < n; i++)//на деле просто динамическая матрица 
	{
		a[i] = new char[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < m; r++)
		{
			a[i][r] = rand() % 26+65; //Коды символов английских больщих букв
			cout << a[i][r] << " ";
		}
		cout << endl;
	}
	//До этого момента ее инициализировали и создавали
	int counter = 0; // Счетчик уникальных элементов
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < m; r++)
		{
			for (int t = 0; t < n; t++)
			{
				for (int h = 0; h < m; h++)
				{
					if (a[i][r] == a[t][h] && t != i && r != h) { //Сравниваем каждый элемент матрицы с каждым
						a[t][h] = '5';                    //если есть похожий то заменяем его пятеркой))
					}
				}
			}
		}
	}
	

	for (int i = 0; i < n; i++) // считаем кол-во символов (5 - ки не учитываем так это повторяющиеся символы)
	{
		for (int r = 0; r < m; r++)
		{
			if (a[i][r] != '5') {
				counter++;
			}
		}
		cout << endl;
	}

	cout << "The number of elemnts is: " << counter << endl; //gg
	system("pause");
	return 0;
}
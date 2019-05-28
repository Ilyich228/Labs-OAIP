#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Product
{
	string name;
	int price;
	int cnt;
	int month;
};

int linearSearch(vector<Product>, int);
int binarySearch(vector<Product>, int);

int menu();
void inputData(vector<Product>&);
void loadData(vector<Product>&, string);
void saveData(vector<Product>, string);
void printReport(vector<Product>, ostream&);
void printReportToFile(vector<Product>, string);
void search(vector<Product>);

int main()
{
	string name;
	vector<Product> products(30);

	while (true)
	{
		switch (menu())
		{
		case 1: cout << "Enter file name: " << endl; cin >> name; break;
		case 2: inputData(products); break;
		case 3: loadData(products, name); break;
		case 4: saveData(products, name); break;
		case 5: printReport(products, cout); break;
		case 6: printReportToFile(products, name); break;
		case 7: return 0;
		default: "Invalid operation!";
		}

		system("pause && cls");
	}
}

int linearSearch(vector<Product> products, int price)
{
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].price == price)
		{
			return i;
		}
	}

	return -1;
}

int binarySearch(vector<Product> products, int price)
{
	int i = 0, j = products.size() - 1, m;
	while (i < j)
	{
		m = (i + j) / 2;
		if (price > products[m].price)
			i = m + 1;
		else
			j = m;
	}
	if (products[i].price == price)
		return i;
	else
		return -1;
}

int menu() // Меню
{
	cout << "Choose:" << endl;
	cout << "1. Enter file name" << endl;
	cout << "2. Input data" << endl;
	cout << "3. Load data from file" << endl;
	cout << "4. Save data to file" << endl;
	cout << "5. Write result" << endl;
	cout << "6. Write to file" << endl;
	cout << "7. Exit" << endl;
	int i;
	cin >> i;

	system("cls");
	return i;
}

void inputData(vector<Product>& products) // Ввести список
{
	int n;

	cout << "Enter number of products: " << endl;
	cin >> n;

	products.clear();
	products.resize(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Enter name: ";
		cin >> products[i].name;
		cout << "Enter cnt: "; // TODO
		cin >> products[i].cnt;
		cout << "Enter price: ";
		cin >> products[i].price;
		cout << "Enter month: ";
		cin >> products[i].month;
	}
}

void saveData(vector<Product> products, string path)
{
	ofstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	size_t size = products.size();

	stream.write((char*)& size, sizeof(size_t));
	stream.write((char*)products.data(), products.size() * sizeof(Product));

	stream.close();
}

void loadData(vector<Product>& products, string path)
{
	ifstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	Product temp;

	size_t size = 0;
	stream.read((char*)& size, sizeof(size_t));

	products.clear();
	products.resize(size);

	stream.read((char*)products.data(), size * sizeof(Product));

	cout << size << endl;
	for (auto data : products)
	{
		cout << data.name << " " << data.cnt << " " << data.month << " " << data.price << endl;
	}

	stream.close();
}

void selectionSort(vector<Product>& products)
{
	for (int i = 0; i < products.size() - 1; i++)
	{
		int pos = i;

		for (int j = i + 1; j < products.size(); j++)
		{
			if (products[j].price < products[pos].price)
			{
				pos = j;
			}
		}

		Product temp = products[i];
		products[i] = products[pos];
		products[pos] = temp;
	}
}

void qsortHelper(vector<Product>& products, int l, int r)
{
	if (l < r)
	{
		int pivot = products[(l + r) / 2].price, i = l, j = r;

		while (i <= j)
		{
			while (products[i].price < pivot) i++;
			while (products[j].price > pivot) j--;

			if (i <= j) {
				Product temp = products[i];
				products[i] = products[j];
				products[j] = temp;
				i++; j--;
			}
		}

		qsortHelper(products, l, j);
		qsortHelper(products, i, r);
	}
}

void qsort(vector<Product>& products)
{
	qsortHelper(products, 0, products.size() - 1);
}

void printReport(vector<Product> products, ostream& output)
{
	output << "unsorted:" << endl;

	for (auto i : products)
	{
		output << "Price: " << i.price << endl;
		output << "Name: " << i.name << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "selection sort:" << endl;
	vector<Product> data_copy = products;

	selectionSort(data_copy);

	for (auto i : data_copy)
	{
		output << "Price: " << i.price << endl;
		output << "Name: " << i.name << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "qsort:" << endl;
	data_copy = products;

	qsort(data_copy);

	for (auto i : data_copy)
	{
		output << "Price: " << i.price << endl;
		output << "Name: " << i.name << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "==========search==========" << endl;

	int price = 150000;
	cout << "Price " << price << endl;

	cout << "linear: " << linearSearch(data_copy, price) << endl;
	cout << "binary: " << binarySearch(data_copy, price) << endl;

}

void printReportToFile(vector<Product> products, string path)
{
	ofstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	printReport(products, stream);

	stream.close();
}
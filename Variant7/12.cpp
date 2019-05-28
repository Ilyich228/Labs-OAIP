#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Detail
{
	int id;
	int cnt;
	int month;
};

int linearSearch(vector<Detail>, int);
int binarySearch(vector<Detail>, int);

int menu();
void inputData(vector<Detail>&);
void loadData(vector<Detail>&, string);
void saveData(vector<Detail>, string);
void printReport(vector<Detail>, ostream&);
void printReportToFile(vector<Detail>, string);
void search(vector<Detail>);

int main()
{
	string name;
	vector<Detail> details(30);

	while (true)
	{
		switch (menu())
		{
		case 1: cout << "Enter file name: " << endl; cin >> name; break;
		case 2: inputData(details); break;
		case 3: loadData(details, name); break;
		case 4: saveData(details, name); break;
		case 5: printReport(details, cout); break;
		case 6: printReportToFile(details, name); break;
		case 7: return 0;
		default: "Invalid operation!";
		}

		system("pause && cls");
	}
}

int linearSearch(vector<Detail> details, int id)
{
	for (int i = 0; i < details.size(); i++)
	{
		if (details[i].id == id)
		{
			return i;
		}
	}

	return -1;
}

int binarySearch(vector<Detail> details, int id)
{
	int i = 0, j = details.size() - 1, m;
	while (i < j)
	{
		m = (i + j) / 2;
		if (id > details[m].id)
			i = m + 1; 
		else
			j = m;
	}
	if (details[i].id == id)
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

void inputData(vector<Detail>& details) // Ввести список
{
	int n;

	cout << "Enter number of details: " << endl;
	cin >> n;

	details.clear();
	details.resize(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Enter ID: ";
		cin >> details[i].id;
		cout << "Enter cnt: "; // TODO
		cin >> details[i].cnt;
		cout << "Enter month: ";
		cin >> details[i].month;
	}
}

void saveData(vector<Detail> details, string path)
{
	ofstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	size_t size = details.size();

	stream.write((char*)& size, sizeof(size_t));
	stream.write((char*)details.data(), details.size() * sizeof(Detail));

	stream.close();
}

void loadData(vector<Detail>& details, string path)
{
	ifstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	Detail temp;

	size_t size = 0;
	stream.read((char*)& size, sizeof(size_t));

	details.clear();
	details.resize(size);

	stream.read((char*)details.data(), size * sizeof(Detail));

	cout << size << endl;
	for (auto data : details)
	{
		cout << data.id << " " << data.cnt << " " << data.month << endl;
	}

	stream.close();
}

vector<Detail> getAListOfDetailsMadeInLastMonth(vector<Detail> details)
{
	int currentMonth;
	cout << "Print number of currrent month" << endl;
	cin >> currentMonth;

	int lastMonth = currentMonth - 1 > 0 ? currentMonth - 1 : 12;

	vector<Detail> result;

	for (auto detail : details)
	{
		if (detail.month == lastMonth)
		{
			result.push_back(detail);
		}
	}

	return result;
}

void selectionSort(vector<Detail>& details)
{
	for (int i = 0; i < details.size() - 1; i++)
	{
		int pos = i;

		for (int j = i + 1; j < details.size(); j++)
		{
			if (details[j].id < details[pos].id)
			{
				pos = j;
			}
		}

		Detail temp = details[i];
		details[i] = details[pos];
		details[pos] = temp;
	}
}

void qsortHelper(vector<Detail>& details, int l, int r)
{
	if (l < r)
	{
		int pivot = details[(l + r) / 2].id, i = l, j = r;

		while (i <= j)
		{
			while (details[i].id < pivot) i++;
			while (details[j].id > pivot) j--;

			if (i <= j) {
				Detail temp = details[i];
				details[i] = details[j];
				details[j] = temp;
				i++; j--;
			}
		}

		qsortHelper(details, l, j);
		qsortHelper(details, i, r);
	}
}

void qsort(vector<Detail>& details)
{
	qsortHelper(details, 0, details.size() - 1);
}

void printReport(vector<Detail> details, ostream& output)
{
	//vector<Detail> data = getAListOfDetailsMadeInLastMonth(details);

	output << "unsorted:" << endl;

	for (auto i : details)
	{
		output << "ID: " << i.id << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "selection sort:" << endl;
	vector<Detail> data_copy = details;

	selectionSort(data_copy);

	for (auto i : data_copy)
	{
		output << "ID: " << i.id << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "qsort:" << endl;
	data_copy = details;

	qsort(data_copy);

	for (auto i : data_copy)
	{
		output << "ID: " << i.id << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}

	cout << "==========search==========" << endl;

	int id = 9383;
	cout << "ID " << id << endl;

	cout << "linear: " << linearSearch(data_copy, id) << endl;
	cout << "binary: " << binarySearch(data_copy, id) << endl;

}

void printReportToFile(vector<Detail> details, string path)
{
	ofstream stream(path);

	if (!stream.is_open())
	{
		cerr << "I/O error: Cannot open file \"" << path << "\"";
		exit(1);
	}

	printReport(details, stream);

	stream.close();
}
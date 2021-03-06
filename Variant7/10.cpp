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


int menu();
void inputData(vector<Detail>&);
void loadData(vector<Detail>&, string);
void saveData(vector<Detail>, string);
void printReport(vector<Detail>, ostream&);
void printReportToFile(vector<Detail>, string);

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

	stream.write((char *)&size, sizeof(size_t));
	stream.write((char *)details.data(), details.size() * sizeof(Detail));

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
	stream.read((char*)&size, sizeof(size_t));

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

	int lastMonth = currentMonth - 1 > 0 ? currentMonth - 1: 12;
	
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

void printReport(vector<Detail> details, ostream& output)
{
	//auto data = //
	vector<Detail> data = getAListOfDetailsMadeInLastMonth(details);


	for (auto i : data)
	{
		output << "ID: " << i.id << endl;
		output << "Count: " << i.cnt << endl;
		output << "Month: " << i.month << endl;
		output << "----------------------------" << endl;
	}
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
#include <iostream>

using namespace std;

struct MainStack {
	int data;
	MainStack* next;
};

void AddDataToStack(int data, MainStack** top) {
	MainStack* temp = new MainStack;
	temp->data = data;
	if (!top) {
		*top = temp;
	}
	else {
		temp->next = *top;
		*top = temp;
	}
}

void PrintStack(MainStack* top) {
	MainStack* temp = top;
	while (temp) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void DeleteDataFromStack(MainStack* top) {
	MainStack* temp1 = top->next;
	MainStack* temp2 = top->next->next;
	top->next = top->next->next->next;
	delete temp1;
	delete temp2;
}

double CalculateMeanValue(MainStack* top) {
	MainStack* temp = top;
	int i = 0;
	double grrr = 0;
	while (temp) {
		i++;
		grrr += temp->data;
		temp = temp->next;
	}
	return grrr / i;
}

int main()
{
	//Create and fill main stack:
	MainStack* top = NULL;
	for (int i = 0; i < 5; i++) {
		AddDataToStack(i, &top);
	}
	cout << "Print main stack:" << endl;
	PrintStack(top);
	/*//Calculate Mean Value:
	double middle = CalculateMeanValue(top);
	cout << "Middle value is " << middle << endl;
	//Create new stack and fill positive data;
	MainStack* top1 = NULL;
	for (double i = 0; i < 5; i++) {
		if (i > middle) {
			AddDataToStack(i, &top1);
		}
	}
	cout << "New stack: " << endl;
	PrintStack(top1);*/
	DeleteDataFromStack(top);
	
	PrintStack(top);
	return 0;
}
#include <time.h>
#include <iostream>

using namespace std;

struct StackNode
{
	int value;
	StackNode* next;
};

StackNode* Add(StackNode* node, int value)
{
	StackNode* new_node = new StackNode;
	new_node->value = value;
	new_node->next = node;

	return new_node;
}

void Print(StackNode* node)
{
	if (!node)
		return;

	cout << node->value << " ";

	Print(node->next);
}

void DeleteAll(StackNode* node)
{
	if (!node)
		return;

	DeleteAll(node->next);
	delete node;
}

int main()
{
	const int stack_size = 20;
	StackNode* top = nullptr;
	int sum = 0;

	srand(time(0));

	for (int i = 0; i < stack_size; i++)
	{
		// top = Add(top, rand() % 101 - 50);

		int temp;
		cin >> temp;
		top = Add(top, temp);

		sum += top->value;
	}

	cout << "Stack 1: ";

	Print(top);

	cout << endl;

	double average = sum / (double)stack_size;
	StackNode *top2 = nullptr, *current = top;

	//cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;

	while (current)
	{
		if (current->value >= average)
		{
			top2 = Add(top2, current->value);
		}


		current = current->next;
	}

	cout << "Stack 2: ";

	Print(top2);

	cout << endl;


	DeleteAll(top);
	DeleteAll(top2);

	return 0;
}



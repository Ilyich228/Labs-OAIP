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
		//top = Add(top, rand() % 101 - 50);

		int temp;
		cin >> temp;
		top = Add(top, temp);

		sum += top->value;
	}

	cout << "Stack: ";

	Print(top);

	cout << endl;

	double average = sum / (double)stack_size;
	StackNode * current = top;

	//cout << "Sum: " << sum << endl;
	cout << "Average: " << average << endl;

	int cnt = 0;

	while (current)
	{
		if (current->value >= average)
		{
			cnt++;
		}

		current = current->next;
	}

	cout << "Number of elements greater than average: " << cnt << endl;


	DeleteAll(top);

	return 0;
}



#include <iostream>
#include <time.h>

using namespace std;

struct QueueNode
{
	QueueNode* next;
	int value;
};

void Add(QueueNode** front, QueueNode** back, int value)
{
	QueueNode* temp = new QueueNode;
	temp->value = value;
	temp->next = nullptr;

	if (*front && *back)
	{
		(*back)->next = temp;
		(*back) = temp;
	}
	else
	{
		*front = *back = temp;
	}
}

void Print(QueueNode* node)
{
	if (!node)
		return;

	cout << node->value << " ";

	Print(node->next);
}

void DeleteAll(QueueNode* front)
{
	if (front)
	{
		DeleteAll(front->next);
		delete front;
	}
}

int main()
{
	QueueNode* front = nullptr, * back = nullptr;
	const int queue_size = 20;

	srand(time(0));

	for (int i = 0; i < queue_size; i++)
	{
		// Add(&front, &back, rand() % 101 - 50);

		int v;
		cin >> v;

		Add(&front, &back, v);
	}

	Print(front);
	cout << endl;

	
	QueueNode* temp = front, *del = nullptr;

	// удаляем четные числа в начале очереди
	while (temp && temp->value % 2 == 0)
	{
		del = temp;
	
		temp = temp->next;
		front = temp;

		delete del;
	}

	// удаляем четные числа в середине очереди и конце
	while (temp)
	{
		if (temp->next && temp->next->value % 2 == 0)
		{
			if (temp->next == back)
			{
				back = temp;
			}

			del = temp->next;
			temp->next = temp->next->next;
			delete del;
		}
		else
		{
			temp = temp->next;
		}
	}

	Print(front);
	DeleteAll(front);
}
#include <iostream>

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

void DeleteFirstAndLastNode(QueueNode** front, QueueNode** back) 
{
	QueueNode* temp = new QueueNode;
	temp = *front;
	(*front) = (*front)->next;
	delete front;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete back;
	temp->next = NULL;
}

int main() 
{
	QueueNode* front = nullptr, * back = nullptr;
	const int queue_size = 4;
	int value;
	for (int i = 0; i < queue_size; i++)
	{
		cin >> value;
		Add(&front, &back, value);
	}
	Print(front);
	DeleteFirstAndLastNode(&front, &back);
	Print(front);
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

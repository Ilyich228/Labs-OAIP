#include <iostream>

using namespace std;

struct LinkedListNode
{
	int value;
	LinkedListNode* prev, * next;
};

struct LinkedList
{
	LinkedListNode* first, * last;
};

void insertBefore(LinkedList* list, LinkedListNode* node, LinkedListNode* new_node)
{
	if (node == list->first)
	{
		list->first = new_node;
	}

	new_node->prev = node->prev;
	new_node->next = node;

	if (node->prev)
		node->prev->next = new_node;

	node->prev = new_node;
}

void insertAfter(LinkedList* list, LinkedListNode* node, LinkedListNode* new_node)
{
	if (node == list->last)
	{
		list->last = new_node;
	}

	new_node->prev = node;
	new_node->next = node->next;

	if (node->next)
		node->next->prev = new_node;

	node->next = new_node;
}

void addFirst(LinkedList* list, int value)
{
	LinkedListNode* new_node = new LinkedListNode;
	new_node->value = value;
	new_node->prev = nullptr;
	new_node->next = nullptr;

	if (!list->first || !list->last)
	{
		list->first = list->last = new_node;
		return;
	}
	else
	{
		insertBefore(list, list->first, new_node);
	}
}

void addLast(LinkedList* list, int value)
{
	LinkedListNode* new_node = new LinkedListNode;
	new_node->value = value;
	new_node->prev = nullptr;
	new_node->next = nullptr;

	if (!list->first || !list->last)
	{
		list->first = list->last = new_node;
		return;
	}
	else
	{
		insertAfter(list, list->last, new_node);
	}
}

void remove(LinkedList* list, LinkedListNode* node)
{
	if (node == nullptr)
	{
		cerr << "node is null" << endl;
		return;
	}

	if (list->first != list->last)
	{
		if (node == list->first)
		{
			list->first = node->next;
			node->next->prev = nullptr;
		}
		else if (node == list->last)
		{
			list->last = node->prev;
			node->prev->next = nullptr;
		}
		else
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
	}

	delete node;
}

void removeNegativeValues(LinkedList* list)
{
	LinkedListNode* current = list->first;

	while (current)
	{
		LinkedListNode* next = current->next;

		if (current->value < 0)
		{
			remove(list, current);
		}

		current = next;
	}
}

void deleteAll(LinkedList* list)
{
	LinkedListNode* current = list->first;

	while (current)
	{
		LinkedListNode* node_to_del = current;
		current = current->next;

		delete node_to_del;
	}
}

void print(LinkedListNode* first)
{
	if (first)
	{
		cout << first->value << " ";
		print(first->next);
	}
	else
	{
		cout << endl;
	}
}

void merge(LinkedList* result, LinkedList* left, LinkedList* right)
{
	LinkedListNode* l_current = left->first,
		* r_current = right->first;

	// merge to left list
	result->first = left->first;
	result->last = left->last;

	while (l_current && r_current)
	{
		if (l_current->value <= r_current->value)
		{
			l_current = l_current->next;
		}
		else
		{
			LinkedListNode* next = r_current->next;
			insertBefore(result, l_current, r_current);
			r_current = next;
		}
	}

	if (r_current)
	{
		result->last->next = r_current;
		r_current->prev = result->last;

		result->last = right->last;
	}

}

void split(LinkedList* list, LinkedList* left, LinkedList* right)
{
	left->first = left->last = list->first;

	if (!left->first->next)
		return;

	right->first = right->last = list->first->next;


	LinkedListNode* current = list->first->next->next;

	left->first->next = nullptr;
	left->first->prev = nullptr;
	right->first->next = nullptr;
	right->first->prev = nullptr;

	LinkedListNode* next;

	while (current)
	{
		next = current->next;
		insertAfter(left, left->last, current);
		current = next;

		if (current)
		{
			next = current->next;
			insertAfter(right, right->last, current);
			current = next;
		}
	}
}

void mergeSort(LinkedList* list)
{
	if (list->first == list->last)
		return;

	LinkedList * left = new LinkedList, *right = new LinkedList;

	split(list, left, right);
	mergeSort(left);
	mergeSort(right);
	merge(list, left, right);
}

void find(LinkedList * list, int value)
{
	LinkedListNode* current = list->first;
	int cnt = 0; // !

	while (current && current->value != value)
	{
		current = current->next;
		cnt++;
	}

	if (current)
	{
		cout << cnt << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}

void removeLast(LinkedList * list)
{
	LinkedListNode* current = list->first;

	while (current->next->next)
	{
		current = current->next;
	}

	list->last = current; // 
	delete current->next;
	current->next = nullptr;
}

int main()
{
	LinkedList* list = new LinkedList;
	list->first = nullptr;
	list->last = nullptr;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		addLast(list, temp);
	}

	removeNegativeValues(list);
	print(list->first);
	mergeSort(list);
	print(list->first);
	find(list, 6);

	removeLast(list);
	removeLast(list);
	print(list->first);

	deleteAll(list);
}
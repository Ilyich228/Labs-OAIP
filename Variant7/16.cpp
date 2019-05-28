#include <iostream>
#include <string>

using namespace std;

struct BST_Node
{
	string value;
	BST_Node* left, * right;
};

BST_Node* insert(BST_Node* node, string value)
{
	if (!node)
	{
		BST_Node* temp = new BST_Node;
		temp->value = value;
		temp->left = nullptr;
		temp->right = nullptr;
		return temp;
	}

	if (value < node->value)
	{
		node->left = insert(node->left, value);
	}
	else
	{
		node->right = insert(node->right, value);
	}

	return node;
}

bool contains(BST_Node* node, string value)
{
	if (!node)
	{
		return false;
	}

	if (node->value == value)
		return true;

	return value < node->value ? contains(node->left, value) : contains(node->right, value);
}

BST_Node* remove(BST_Node* node, string value)
{
	BST_Node* ps = node, * pr = node, * w = nullptr, * v = nullptr;

	while (ps && (ps->value != value))
	{
		pr = ps;
		if (value < ps->value)
			ps = ps->left;
		else
			ps = ps->right;
	}

	if (!ps) return node;

	if (!ps->left && !ps->right)
	{
		if (ps == pr)
		{
			delete(ps);
			return NULL;
		}
		if (pr->left == ps)	pr->left = NULL;
		else pr->right = NULL;
		delete(ps);
		return node;
	}

	if (!ps->left)
	{
		if (ps == pr)
		{
			ps = ps->right;
			delete(pr);
			return ps;
		}

		if (pr->left == ps) pr->left = ps->right;
		else pr->right = ps->right;
		delete(ps);
		return node;
	}

	if (!ps->right)
	{
		if (ps == pr)
		{
			ps = ps->left;
			delete(pr);
			return ps;
		}

		if (pr->left == ps) pr->left = ps->left;
		else pr->right = ps->left;
		delete(ps);
		return node;
	}


	w = ps->left;
	if (!w->right) w->right = ps->right;
	else
	{
		while (w->right)
		{
			v = w;
			w = w->right;
		}
		v->right = w->left;
		w->left = ps->left;
		w->right = ps->right;
	}

	if (ps == pr)
	{
		delete(ps);
		return w;
	}

	if (pr->left == ps) pr->left = w;
	else pr->right = w;
	delete(ps);
	return node;
}

void removeAll(BST_Node* node)
{
	if (!node)
		return;

	removeAll(node->left);
	removeAll(node->right);

	delete node;
}

void print(BST_Node* node)
{
	if (!node)
		return;

	print(node->left);
	cout << node->value << " ";
	print(node->right);
}

int numberOfSymbols(BST_Node* node)
{
	if (!node)
		return 0;

	return node->value.length() + numberOfSymbols(node->left) + numberOfSymbols(node->right);
}

int main()
{
	int n;
	string temp;
	BST_Node* root = nullptr;

	cout << "Enter n:";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		root = insert(root, temp);
	}

	cout << "Tree: " << endl;
	print(root);
	cout << endl;


	cout << "Number of symbols: " << numberOfSymbols(root);

	removeAll(root);
}

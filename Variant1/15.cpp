#include <iostream>

using namespace std;

struct DoubleEndedQueue
{
	int info;
	DoubleEndedQueue *left, *right;
};

void NewQueue(DoubleEndedQueue** sl, DoubleEndedQueue** sr)
{
	*sl = new DoubleEndedQueue;
	*sr = new DoubleEndedQueue;
	(*sl)->left = NULL;
	(*sl)->right = *sr;
	(*sr)->left = *sl;
	(*sr)->right = NULL;
}

void DeleteQueue(DoubleEndedQueue** sl, DoubleEndedQueue** sr)
{
	DoubleEndedQueue* t;
	while ((*sl)->right != (*sr))
	{
		t = (*sl)->right->right;
		delete (*sl)->right;
		(*sl)->right = t;
	}
	delete* sl;  *sl = NULL;
	delete* sr;  *sr = NULL;
}

void addLeft(DoubleEndedQueue* sp, int inf)
{
	DoubleEndedQueue* spt = new DoubleEndedQueue;
	spt->info = inf;
	spt->left = sp->left;
	spt->right = sp;
	spt->left->right = spt;
	sp->left = spt;
}

void addRight(DoubleEndedQueue* sp, int inf)
{
	DoubleEndedQueue* spt = new DoubleEndedQueue;
	spt->info = inf;
	spt->left = sp;
	spt->right = sp->right;
	sp->right = spt;
	spt->right->left = spt;
}

void PrintQueue(DoubleEndedQueue* sl, DoubleEndedQueue* sr)
{
	DoubleEndedQueue* p = sl;
	while ((p = p->right) != sr)
	{
		cout << p->info << " ";
	}
	cout << endl;
}

int read_del(DoubleEndedQueue* sp)
{
	int inf = sp->info;
	sp->left->right = sp->right;
	sp->right->left = sp->left;
	delete sp;
	return inf;
}

void div2Ochd(DoubleEndedQueue* sl, DoubleEndedQueue* sr, DoubleEndedQueue** slL, DoubleEndedQueue** srL, DoubleEndedQueue** slR, DoubleEndedQueue** srR)
{
	NewQueue(slL, srL);
	NewQueue(slR, srR);
	DoubleEndedQueue* spt = sl->right;
	while (spt != sr)
	{
		addLeft(*srL, read_del(spt));
		spt = sl->right;
		if (spt != sr)
		{
			addLeft(*srR, read_del(spt));
			spt = sl->right;
		}
	}
	delete sl;
	delete sr;
}


void slip(DoubleEndedQueue** sl, DoubleEndedQueue** sr, DoubleEndedQueue* slL, DoubleEndedQueue* srL, DoubleEndedQueue* slR, DoubleEndedQueue* srR)
{
	NewQueue(sl, sr);
	DoubleEndedQueue* sptL = slL->right;
	DoubleEndedQueue* sptR = slR->right;
	while ((sptL != srL) && (sptR != srR))
	{
		if (sptL->info < sptR->info)
		{
			addLeft(*sr, read_del(sptL));
			sptL = slL->right;
		}
		else
		{
			addLeft(*sr, read_del(sptR));
			sptR = slR->right;
		}
	}
	while (sptL != srL)
	{
		addLeft(*sr, read_del(sptL));
		sptL = slL->right;
	}
	delete slL; delete srL;

	while (sptR != srR)
	{
		addLeft(*sr, read_del(sptR));
		sptR = slR->right;
	}
	delete slR; delete srR;
}

void sort(DoubleEndedQueue** sl, DoubleEndedQueue** sr)
{
	DoubleEndedQueue* slL, * srL, * slR, * srR;
	if ((*sl)->right->right == *sr) return;
	div2Ochd(*sl, *sr, &slL, &srL, &slR, &srR);
	sort(&slL, &srL);
	sort(&slR, &srR);
	slip(sl, sr, slL, srL, slR, srR);
}

void search(DoubleEndedQueue * sl, DoubleEndedQueue * sr, int x)
{
	DoubleEndedQueue* p = sl;
	int n = 0;
	while ((p = p->right) != sr)
	{
		n++;
		if (p->info == x) break;
	}

	if (p->info == x)
		cout << "Found. pos=" << n << endl;
	else 
		cout << "Not found!" << endl;

}



int main()
{
	int n, k, nvar = 1;

	cout << "Enter n: ";
	cin >> n;

	DoubleEndedQueue* sl, * sr;
	NewQueue(&sl, &sr);

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		addRight(sl, k);
	}

	cout << "Queue:" << endl;
	PrintQueue(sl, sr);

	cout << "Search:" << nvar << endl;
	search(sl, sr, nvar);

	cout << "Move min to first: " << endl;
	DoubleEndedQueue* p = sl->right;
	DoubleEndedQueue* min = p;
	while ((p = p->right) != sr)
	{
		if (p->info < min->info) min = p;
	}
	if (min != sl->right)
	{
		p = sl->right;
		min->left->right = min->right;
		min->right->left = min->left;
		sl->right = min;
		min->right = p;
		p->left = min;
		min->left = sl;
	}

	PrintQueue(sl, sr);

	cout << "sorted:" << endl;
	sort(&sl, &sr);
	PrintQueue(sl, sr);

	DeleteQueue(&sl, &sr);
	return 0;
}
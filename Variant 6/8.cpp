#include "stdafx.h" 
#include <iostream>
#include <iomanip>
using namespace std;

double Fak(int k)
{

	double proizv;

	if (k%2==0)
	{
		proizv = 2;
		for (int i=4;i<=k;i+=2)
		{
			proizv *= i;
		}
	}
	else
	{
		proizv = 1;
		for (int i = 3; i <= k; i += 2)
		{
			proizv *= i;
		}
	}

	return proizv;
}

int main()
{
	
	double s=0,y,k,c=0;
	
	cout << "-------------------------------------------------\n";
	cout << "|" << setw(6) << "X" << setw(6) << "|" << setw(6) << "S(x)" << setw(6) << "|" << setw(6) << "K" << setw(6) << "|" << setw(6) << "Y(x)" << setw(6) << "|" << endl;
	cout << "-------------------------------------------------\n";

	for (double x = (-0.9);x<=0.9;x+=0.1) 
	{
		if (x < 0.01 && x>-0.01) 
		{
			x = 0;
		}
		k = 2;
		s = 0;
		y = sqrt(1+x)-1-(x/2);

		c = pow(-1,k-1)*( (Fak(2*k-3)/Fak(2*k) ) * pow(x,k) );

		s += c; 

		while (abs(c)> 0.001)
		{
			k++;
			c = pow(-1, k - 1)*((Fak(2 * k - 3) / Fak(2*p)) * pow(x, k));
			s += c;
		}
		cout << "-------------------------------------------------\n";
		cout << "|" << setw(6) << x << setw(6) << "|" << setw(6) << s << setw(6) << "|" << setw(6) << k-1 << setw(6) << "|" << setw(6) << y << setw(6) << "|" << endl;
		cout << "-------------------------------------------------\n";
		
	}

	system("pause");
}
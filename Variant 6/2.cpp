
#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y,f,a,g;
int k;
cout << "Vvedite x "; cin >> x;
cout << "Vvedite y "; cin >> y;
cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 � exp(x) "; cin >> k;
switch(k)
{
case 1: f=sinh(x); break;
case 2: f=pow(x,2); break;
case 3: f=exp(x); break;
default: cout << "Ne vuibrana funkciya "; return 1;
}
a=x*y;
if (a<0.1)
{
cout << "Net rezultata" << endl;
return 1;
} else
	if (a>0.5 && a<10) g=exp(f-fabs(y));
	else 
		if(a<0.5 && a>0.1) g=pow(fabs(f+y),1/3.);
		else 
			g=2*pow(f,2);
cout << "RESULT = " << g << endl;
	return 0;
}


#include "stdafx.h"
#include <math.h>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y,z,a,b,s;
	cout<<"vvedite x,y,z:"<<endl;
	cin>>x>>y>>z;
	a=sqrt(10*(pow(x,1/3.)+pow(x,y+2)));
	b=pow(asin(z),2)-fabs(x-y);
	s=a*b;
	cout<<"result s="<<s<<endl;
	return 0;
}
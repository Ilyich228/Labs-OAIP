
#include "stdafx.h"
#include "string.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char st1[100];
	char b[100];
	int bp=0;
	cout<<"vvedite stroku ";
	gets_s(st1,100);
	int dl=strlen(st1);
    for(int i=0;i<dl;i++)
	{
		if(st1[i]>='0' && st1[i]<='9' || st1[i]=='-')
		{
			b[bp] = st1[i];
			bp++;
		}
		else
		{
			if(bp>0)
			{
				for(int j=0;j<bp;j++)
				{
					cout<<b[j];
				}
				cout<<" ";
				bp=0;
			}
		}
	}

	system("pause");
	return 0;
}


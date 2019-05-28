#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, b, f;
	int code;

	cout << "Chose f(x): 0 - sh(x), 1 - x^2, 2 - exp(x)" << endl;
	cin >> code;

	cout << "Enter x, y, b:" << endl;
	cin >> x >> y >> b;

	switch (code)
	{
	case 0:
		f = sinh(x);
		break;
	case 1:
		f = x * x;
		break;
	case 2:
		f = exp(x);
		break;
	default:
		cout << "Неверный ввод!";
		return 0;
	}



	if (x * b > 1 && x * b < 10)
	{
		cout << exp(f);
	}
	else if (x * b > 12 && x * b > 40)
	{
		cout << pow(fabs(f + 4 * y), 1./ 3);
	}
	else
	{
		cout << y * f * f;
	}

}
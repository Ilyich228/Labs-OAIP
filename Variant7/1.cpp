#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, z;
	cin >> x >> y >> z;
    
	double a = 5 * atan(x),
		b = 0.25 * acos(x),
		c = x + 3 * fabs(x - y) + x * x,
		d = fabs(x - y) * z + x * x;

	double s = a - b * c / d;
	cout << s;

	return 0;
}
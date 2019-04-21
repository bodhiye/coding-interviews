#include <iostream>

using namespace std;

double power(double base, int exponent)
{
	int exp = abs(exponent);
	double ans = 1.0;
	while (exp)
	{
		if (exp & 1)ans *= base;
		base *= base;
		exp >>= 1;
	}
	return exponent < 0 ? 1 / ans : ans;
}

int main()
{
	ios::sync_with_stdio(false);
	double a;
	int b;
	cin >> a >> b;
	cout << power(a, b) << endl;
	return 0;
}
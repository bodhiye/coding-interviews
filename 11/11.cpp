#include <iostream>

using namespace std;

int  NumberOf1(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << NumberOf1(n);
	return 0;
}
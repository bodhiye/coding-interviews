#include <iostream>

using namespace std;

int jumpFloor(int number)
{
	return 1 << --number;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << jumpFloor(n);
	return 0;
}
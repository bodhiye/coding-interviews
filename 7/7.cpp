#include <iostream>

using namespace std;

int dp[40];

int Fibonacci(int n)
{
	if (n == 0 || n == 1)return n;
	if (dp[n])return dp[n];
	else
		return dp[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << Fibonacci(n);
	return 0;
}
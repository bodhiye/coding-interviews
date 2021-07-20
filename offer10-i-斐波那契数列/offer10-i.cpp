#include <iostream>

using namespace std;

int dp[101];

int fib(int n)
{
	if (n == 0 || n == 1)return n;
	if (dp[n])return dp[n];
	else
		return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cout << fib(100) << endl;
	return 0;
}

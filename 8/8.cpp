#include <iostream>

using namespace std;

int dp[101];

int jumpFloor(int number)
{
	if (number == 1 || number == 2)return number;
	if (dp[number])return dp[number];
	else
		return dp[number] = jumpFloor(number - 1) + jumpFloor(number - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << jumpFloor(n);
	return 0;
}
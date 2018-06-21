#include <iostream>

using namespace std;

int dp[101];

int rectCover(int number)
{
	if (number < 1)return 0;
	if (number == 1 || number == 2)return number;
	if (dp[number])return dp[number];
	else
		return dp[number] = rectCover(number - 1) + rectCover(number - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << rectCover(n) << endl;
	return 0;
}
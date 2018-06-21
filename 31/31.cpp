#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if (n < 1)return 0;
	int count = 0, base = 1, round = n;
	while (round)
	{
		int i = round % 10;
		round /= 10;
		count += round * base;
		if (i == 1)
			count += (n % base + 1);
		else if (i > 1)
			count += base;
		base *= 10;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << NumberOf1Between1AndN_Solution(n) << endl;
	return 0;
}
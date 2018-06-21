#include <iostream>
#include <vector>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int len = numbers.size();
	int count = 0, ans;
	for (int i = 0; i < len; i++)
	{
		if (!count)
		{
			ans = numbers[i];
			count = 1;
		}
		else
		{
			if (ans == numbers[i])
				count++;
			else
				count--;
		}
	}
	count = 0;
	for (int i = 0; i < len; i++)
		if (numbers[i] == ans)count++;
	if (count * 2 > len)
		return ans;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, temp;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cout << MoreThanHalfNum_Solution(v) << endl;
	return 0;
}
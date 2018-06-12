#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetUglyNumber_Solution(int index)
{
	if (!index)return 0;
	vector<int> v(index);
	v[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0;
	for (int i = 1; i < index; i++)
	{
		v[i] = min(v[t2] * 2, min(v[t3] * 3, v[t5] * 5));
		if (v[i] == v[t2] * 2)t2++;
		if (v[i] == v[t3] * 3)t3++;
		if (v[i] == v[t5] * 5)t5++;
	}
	return v[index - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << GetUglyNumber_Solution(n);
	return 0;
}
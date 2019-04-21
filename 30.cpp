#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	int len = array.size(), temp = array[0], ans = temp;
	for (int i = 1; i < len; i++)
	{
		temp = max(temp + array[i], array[i]);
		ans = max(temp, ans);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> a;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	cout << FindGreatestSumOfSubArray(a) << endl;
	return 0;
}
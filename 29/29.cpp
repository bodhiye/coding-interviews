#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int left, int right)
{
	int pivot = a[left];
	while (left < right)
	{
		while (left < right&&a[right] >= pivot)
			right--;
		a[left] = a[right];
		while (left < right&&a[left] <= pivot)
			left++;
		a[right] = a[left];
	}
	a[left] = pivot;
	return left;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> v;
	int len = input.size();
	if (len == 0 || k > len || k <= 0) return v;
	int left = 0, right = len - 1;
	int pos = partition(input, left, right);
	while (pos != k - 1)
	{
		if (pos > k - 1)
			right = pos - 1;
		else
			left = pos + 1;
		pos = partition(input, left, right);
	}
	for (int i = 0; i < k; i++)
		v.push_back(input[i]);
	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> input, v;
	int n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	v = GetLeastNumbers_Solution(input, k);
	for (int i = 0; i < k; i++)
		cout << v[i] << ',';
	cout << endl;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int temp[200001];
long long cnt = 0;

void merge(vector<int> &a, int start, int mid, int end)
{
	int i = start, j = mid + 1, index = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		else
		{
			cnt += (mid - i + 1);
			temp[index++] = a[j++];
		}
	}
	while (i <= mid)temp[index++] = a[i++];
	while (j <= end)temp[index++] = a[j++];
	for (int i = 0; i < index; i++)
		a[start + i] = temp[i];
}

void mergesort(vector<int> &data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;
		mergesort(data, start, mid);
		mergesort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

int InversePairs(vector<int> data)
{
	int len = data.size();
	if (!len)return 0;
	mergesort(data, 0, len - 1);
	return cnt % 1000000007;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> a;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	cout << InversePairs(a);
	return 0;
}
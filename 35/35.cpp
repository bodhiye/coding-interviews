#include <iostream>
#include <vector>

using namespace std;
int temp[100001];
int cnt;

void merge(vector<int> a, int start, int mid, int end)
{
	int i = start, j = mid + 1, index = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
			temp[index++] = a[i++];
		else
		{
			cnt += (mid - i + 1) % 1000000007;
			temp[index++] = a[j++];
		}
	}
	while (i <= mid)temp[index++] = a[i++];
	while (j <= end)temp[index++] = a[j++];
	for (int i = 0; i < index; i++)
		a[start + i] = temp[i];
}

void mergesort(vector<int> a, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

int InversePairs(vector<int> data)
{
	int len = data.size();
	if (!len) return 0;
	mergesort(data, 0, len - 1);
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> v;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << InversePairs(v);
	return 0;
}
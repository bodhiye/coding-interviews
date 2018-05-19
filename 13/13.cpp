#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array)
{
	int begin = 0, from, len = array.size();
	while (begin < len)
	{
		while (begin < len && (array[begin] & 1))
		{
			begin++;
		}
		from = begin + 1;
		while (from < len && !(array[from] & 1))
		{
			from++;
		}
		if (from < len)
		{
			int temp = array[from];
			for (int i = from - 1; i >= begin; i--)
			{
				array[i + 1] = array[i];
			}
			array[begin++] = temp;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	reOrderArray(v);
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
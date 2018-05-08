#include <iostream>
#include <vector>

using namespace std;

bool find(int target, vector<vector<int> > array)
{
	int rows = array.size(), cols = array[0].size();
	int i = rows - 1, j = 0;
	while (i >= 0 && j < cols)
	{
		if (target < array[i][j])
			i--;
		else if (target > array[i][j])
			j++;
		else
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<vector<int> > array;
	vector<int> v;
	int m, n, target, temp;
	cin >> m >> n >> target;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		array.push_back(v);
		v.clear();
	}
	cout << find(target, array);
	return 0;
}
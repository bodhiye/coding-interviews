#include <iostream>
#include <vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int> >& matrix, int target)
{
	int i = matrix.size() - 1, j = 0;
	while (i >= 0 && j < matrix[0].size())
	{
		if (target < matrix[i][j])
			i--;
		else if (target > matrix[i][j])
			j++;
		else
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int a[][5] = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	};
	vector<vector<int> > matrix(5, vector<int> (5, 0));
	for (int m = 0; m < matrix.size(); m++)
	{
		for (int n = 0; n < matrix[m].size(); n++)
		{
			matrix[m][n] = a[m][n];
		}
	}
	cout << findNumberIn2DArray(matrix, 5) << endl;
	cout << findNumberIn2DArray(matrix, 20) << endl;
	return 0;
}

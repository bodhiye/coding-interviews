#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> res;
	int row = matrix.size(), col = matrix[0].size();
	int circle = ((row < col ? row : col) + 1) / 2;
	for (int i = 0; i < circle; i++)
	{
		for (int j = i; j < col - i; j++)
			res.push_back(matrix[i][j]);
		for (int k = i + 1; k < row - i; k++)
			res.push_back(matrix[k][col - i - 1]);
		for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--)
			res.push_back(matrix[row - i - 1][m]);
		for (int n = row - i - 2; (n > i) && (col - i - 1 != i); n--)
			res.push_back(matrix[n][i]);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<vector<int> > vv;
	vector<int> res, v;
	int n, m, temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		vv.push_back(v);
	}
	res = printMatrix(vv);
	vector<int>::iterator it;
	for (it = res.begin(); it != res.end(); it++)
		cout << *it << " ";
	return 0;
}
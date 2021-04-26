#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> >& matrix)
{
	vector<int> res;
    if (matrix.size() < 1 || matrix[0].size() < 1)
        return res;
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
    int a[][5] = {
		{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
	};
	vector<vector<int> > matrix(3, vector<int> (3, 0));
	for (int m = 0; m < matrix.size(); m++)
	{
		for (int n = 0; n < matrix[m].size(); n++)
		{
			matrix[m][n] = a[m][n];
		}
	}
    vector<int> res;
    res = printMatrix(matrix);
    vector<int>::iterator it;
	for (it = res.begin(); it != res.end(); it++)
		cout << *it << " ";
    cout << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int getSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int moving(int threshold, int i, int j, int rows, int cols, vector<vector<int> > &flag) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || flag[i][j] == 1 || getSum(i) + getSum(j) > threshold)
        return 0;
    flag[i][j] = 1;
    return moving(threshold, i - 1, j, rows, cols, flag) + moving(threshold, i + 1, j, rows, cols, flag) +
           moving(threshold, i, j - 1, rows, cols, flag) + moving(threshold, i, j + 1, rows, cols, flag) + 1;
}

int movingCount(int threshold, int rows, int cols) {
    vector<vector<int> > flag(rows);
    for (int i = 0; i < rows; i++)
        flag[i].resize(cols, 0);
    return moving(threshold, 0, 0, rows, cols, flag);
}

int main() {
    ios::sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    cout << movingCount(k, m, n);
    return 0;
}

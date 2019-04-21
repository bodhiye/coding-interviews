#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool path(char *matrix, int rows, int cols, int i, int j, char *str, int k, vector<bool> flag) {
    int index = i * cols + j;
    if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index])
        return false;
    if (k == strlen(str) - 1)
        return true;
    flag[index] = true;
    if (path(matrix, rows, cols, i - 1, j, str, k + 1, flag) || path(matrix, rows, cols, i + 1, j, str, k + 1, flag) ||
        path(matrix, rows, cols, i, j - 1, str, k + 1, flag) || path(matrix, rows, cols, i, j + 1, str, k + 1, flag))
        return true;
    flag[index] = false;
    return false;
}

bool hasPath(char *matrix, int rows, int cols, char *str) {
    vector<bool> flag(rows * cols, false);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (path(matrix, rows, cols, i, j, str, 0, flag))
                return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int rows, cols;
    char s[101], str[101];
    cin >> rows >> cols >> s >> str;
    cout << hasPath(s, rows, cols, str);
    return 0;
}

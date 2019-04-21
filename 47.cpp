#include <iostream>

using namespace std;

int Sum_Solution(int n) {
    int res = n;
    res && (res += Sum_Solution(n - 1));
    return res;
}

int Sum_Solution1(int n) {
    bool a[n][n + 1];
    return sizeof(a) >> 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << Sum_Solution(n) << endl;
    cout << Sum_Solution1(n);
    return 0;
}

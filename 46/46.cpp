#include <iostream>
#include <vector>

using namespace std;

int LastRemaining_Solution(int n, int m) {
    if (n < 1 || m < 1)return -1;
    int count = n, step = 0, i = -1;
    vector<int> v(n);
    while (count) {
        i++;
        i = i % n;
        if (v[i] == -1)continue;
        step++;
        if (step == m) {
            v[i] = -1;
            step = 0;
            count--;
        }
    }
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    cout << LastRemaining_Solution(n, m);
    return 0;
}

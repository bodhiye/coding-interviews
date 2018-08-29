#include <iostream>
#include <vector>

using namespace std;

bool duplicate(int numbers[], int length, int *duplication) {
    vector<bool> b = {0};
    for (int i = 0; i < length; i++) {
        if (b[numbers[i]]) {
            *duplication = numbers[i];
            return true;
        }
        b[numbers[i]] = true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n, res;
    int a[1001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << duplicate(a, n, &res) << endl;
    cout << res;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

void Insert(int num) {
    v.push_back(num);
    n = v.size();
    for (int i = n - 1; i > 0 && v[i] < v[i - 1]; --i)
        swap(v[i], v[i - 1]);
}

double GetMedian() {
    return (v[(n - 1) >> 1] + v[n >> 1]) / 2.0;
}

int main() {
    ios::sync_with_stdio(false);
    int m, tmp;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        Insert(tmp);
    }
    cout << GetMedian();
    return 0;
}

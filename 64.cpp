#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> v;
    deque<int> d;
    for (unsigned int i = 0; i < num.size(); ++i) {
        while (d.size() && num[d.back()] <= num[i])
            d.pop_back();
        if (d.size() && i - d.front() + 1 > size)
            d.pop_front();
        d.push_back(i);
        if (size && i + 1 >= size)
            v.push_back(num[d.front()]);
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> v, res;
    int n, k, tmp;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    res = maxInWindows(v, k);
    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << " ";
    return 0;
}

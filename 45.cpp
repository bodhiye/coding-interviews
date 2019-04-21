#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    int len = numbers.size(), zero = 0, internal = 0;
    if (len == 0)return false;
    for (int i = 0; i < len - 1; i++) {
        if (numbers[i] == 0) {
            zero++;
            continue;
        }
        if (numbers[i] == numbers[i + 1])return false;
        internal += (numbers[i + 1] - numbers[i] - 1);
    }
    if (zero >= internal)return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> v;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cout << IsContinuous(v);
    return 0;
}

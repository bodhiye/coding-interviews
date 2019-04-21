#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> m;
vector<int> v;

void Insert(char ch) {
    v.push_back(ch);
    m[ch]++;
}

char FirstAppearingOnce() {
    for (auto it = v.begin(); it != v.end(); ++it)
        if (m[*it] == 1)
            return *it;
    return '#';
}

int main() {
    ios::sync_with_stdio(false);
    char c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        Insert(c);
    }
    cout << FirstAppearingOnce();
    return 0;
}

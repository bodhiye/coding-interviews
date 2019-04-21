#include <iostream>
#include <vector>

using namespace std;

string LeftRotateString(string str, int n) {
    int len = str.length();
    str += str;
    if (len == 0)
        return "";
    n = n % len;
    return str.substr(n, len);
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    cout << LeftRotateString(s, n);
    return 0;
}

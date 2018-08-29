#include <iostream>

using namespace std;

int StrToInt(string str) {
    int len = str.length();
    int flag = 1;
    long long res = 0;
    if (!len)return 0;
    if (str[0] == '-')flag = -1;
    for (int i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < len; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))return 0;
        res = res * 10 + (str[i] - '0');
    }
    return res * flag;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << StrToInt(s);
    return 0;
}

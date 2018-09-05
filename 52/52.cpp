#include <iostream>

using namespace std;

bool match(char *str, char *pattern) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    if (*(pattern + 1) != '*') {
        if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match(str + 1, pattern + 1);
        else
            return false;
    } else {
        if (*str == *pattern || (*str != '\0' && *pattern == '.'))
            return match(str, pattern + 2) || match(str + 1, pattern);
        else
            return match(str, pattern + 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    char a[101], b[101];
    cin >> a >> b;
    cout << match(a, b);
    return 0;
}

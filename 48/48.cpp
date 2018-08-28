#include <iostream>

using namespace std;

int Add(int num1, int num2) {
    while (num2) {
        int carry = num1 ^num2;
        num2 = (num1 & num2) << 1;
        num1 = carry;
    }
    return num1;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << Add(a, b);
    return 0;
}

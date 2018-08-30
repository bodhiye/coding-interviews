#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int> &A) {
    int len = A.size();
    vector<int> B(len);
    B[0] = 1;
    for (int i = 1; i < len; i++)
        B[i] = B[i - 1] * A[i - 1];
    int temp = 1;
    for (int i = len - 2; i >= 0; i--) {
        temp *= A[i + 1];
        B[i] *= temp;
    }
    return B;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> a, b;
    int temp, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    b = multiply(a);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    return 0;
}

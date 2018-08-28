#include <iostream>
#include <string>

using namespace std;

string ReverseSentence(string str) {
    string res = "", temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            res = " " + temp + res;
            temp = "";
        } else temp += str[i];
    }
    res = temp + res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    cout << ReverseSentence(s);
    return 0;
}

#include <iostream>
#include <string>
#include <map>

using namespace std;

char firstUniqChar(string s)
{
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
        m[s[i]]++;
    for (int i = 0; i < s.length(); i++)
        if (m[s[i]] == 1)
            return s[i];
    return ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cout << firstUniqChar("abaccdeff") << endl;
    return 0;
}
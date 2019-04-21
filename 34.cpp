#include <iostream>
#include <string>
#include <map>

using namespace std;

int FirstNotRepeatingChar(string str)
{
	map<char, int> m;
	for (int i = 0; i < str.length(); i++)
		m[str[i]]++;
	for (int i = 0; i < str.length(); i++)
	{
		if (m[str[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << FirstNotRepeatingChar(s) << endl;
	return 0;
}
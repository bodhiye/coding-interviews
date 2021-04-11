#include <iostream>

using namespace std;

char a[1001];

string replaceSpace(string s)
{
	int count = 0;
	int length = s.size();
	for (int i = 0; i < length; i++)
		if (s[i] == ' ')
			count++;
	int len = length + count * 2;
	s.resize(len);
	while (length--)
	{
		if (s[length] == ' ')
			s[--len] = '0', s[--len] = '2', s[--len] = '%';
		else
			s[--len] = s[length];
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	string s = "We are happy.";
	cout << replaceSpace(s) << endl;
	return 0;
}

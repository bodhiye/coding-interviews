#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

void perm(string str, int begin)
{
	if (begin == str.length())
		res.push_back(str);
	else
	{
		for (int i = begin; i < str.length(); i++)
		{
			if (i != begin && str[i] == str[begin]) continue;
			swap(str[begin], str[i]);
			perm(str, begin + 1);
			swap(str[begin], str[i]);
		}
	}
}

vector<string> Permutation(string str)
{
	if (str.length() == 0) return res;
	perm(str, 0);
	sort(res.begin(), res.end());
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<string> v = Permutation(s);
	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << endl;
	return 0;
}
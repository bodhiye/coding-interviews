#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(int &a, int &b)
{
	string aa = to_string(a);
	string bb = to_string(b);
	return (aa + bb) < (bb + aa);
}

string PrintMinNumber(vector<int> numbers)
{
	string res;
	sort(numbers.begin(), numbers.end(), cmp);
	vector<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		int temp = *it;
		res += to_string(temp);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cout << PrintMinNumber(v);
	return 0;
}
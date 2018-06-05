#include <iostream>
#include <vector>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence)
{
	int len = sequence.size();
	if (!len)return false;
	while (--len)
	{
		int i = 0;
		while (sequence[i++] < sequence[len]);
		while (sequence[i++] > sequence[len]);
		if (i < len)return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> v;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	cout << VerifySquenceOfBST(v);
	return 0;
}
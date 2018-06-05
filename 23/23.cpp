#include <iostream>
#include <vector>

using namespace std;

//·ÇµÝ¹é½â·¨
//bool VerifySquenceOfBST(vector<int> sequence)
//{
//	int len = sequence.size();
//	if (!len)return false;
//	while (--len)
//	{
//		int i = 0;
//		while (sequence[i++] < sequence[len]);
//		while (sequence[i++] > sequence[len]);
//		if (i < len)return false;
//	}
//	return true;
//}

bool judge(vector<int>& v, int l, int r)
{
	if (l >= r)return true;
	int i = r;
	while (i > l&&v[--i] > v[r]);
	for (int j = i - 1; j >= l; j--)
		if (v[j] > v[r])return false;
	return judge(v, l, i - 1) && judge(v, i, r - 1);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	int len = sequence.size();
	if (!len)return false;
	return judge(sequence, 0, len - 1);
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
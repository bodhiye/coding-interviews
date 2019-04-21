#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> s;
	for (int i = 0, j = 0; i < pushV.size(); i++)
	{
		s.push(pushV[i]);
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			j++;
		}
	}
	return s.empty();
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> pushV, popV;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		pushV.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		popV.push_back(temp);
	}
	cout << IsPopOrder(pushV, popV) << endl;
	return 0;
}
#include <iostream>
#include <stack>

using namespace std;

stack<int> s, smin;

void push(int value)
{
	s.push(value);
	if (smin.empty() || value <= smin.top())
		smin.push(value);
}

void pop()
{
	if (s.top() == smin.top())
		smin.pop();
	s.pop();
}

int top()
{
	return s.top();
}

int min()
{
	return smin.top();
}

int main()
{
	ios::sync_with_stdio(false);
	int temp;
	while (1)
	{
		cin >> temp;
		if (!temp)
			break;
		push(temp);
	}
	cout << min();
	return 0;
}
#include <iostream>

using namespace std;

char a[1001];

void replaceSpace(char *str, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
		if (str[i] == ' ')
			sum++;
	int len = length + sum * 2;
	while (length--)
	{
		if (str[length] == ' ')
			str[--len] = '0', str[--len] = '2', str[--len] = '%';
		else
			str[--len] = str[length];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.get(a, 1001);
	int len = strlen(a);
	replaceSpace(a, len);
	cout << a << endl;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();
	if (!len)
		return 0;
	int low = 0, high = len - 1;
	while (low < high)
	{
		int mid = low + ((high - low) >> 1);
		if (rotateArray[mid] > rotateArray[high])
			low = mid + 1;
		else if (rotateArray[mid] < rotateArray[high])
			high = mid;
		else
			high--;
	}
	return rotateArray[low];
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
	cout << minNumberInRotateArray(v) << endl;
	return 0;
}
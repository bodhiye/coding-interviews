#include <iostream>
#include <vector>

using namespace std;

int findRepeatNumber(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
		if (nums[i] != i)
        {
			if (nums[i] == num)
            {
				return nums[i];
			}
			nums[i], num = num, nums[i];
		}
	}
	return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    int a[] = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums(a, a+7);
    cout << findRepeatNumber(nums) << endl;
    return 0;
}

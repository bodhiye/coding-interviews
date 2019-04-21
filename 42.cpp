#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    int low = 0, high = array.size() - 1;
    vector<int> res;
    while (low < high) {
        if (array[low] + array[high] == sum) {
            res.push_back(array[low]);
            res.push_back(array[high]);
            return res;
        } else if (array[low] + array[high] < sum)
            low++;
        else high--;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int sum, n, temp;
    vector<int> v;
    vector<int> res;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> sum;
    res = FindNumbersWithSum(v, sum);
    cout << res[0] << " " << res[1];
    return 0;
}

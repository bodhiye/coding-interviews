#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > res;
    int low = 1, high = 2;
    while (low < high) {
        int tempsum = ((low + high) * (high - low + 1) >> 1);
        if (tempsum == sum) {
            vector<int> temp;
            for (int i = low; i <= high; i++)
                temp.push_back(i);
            res.push_back(temp);
            low++;
        } else if (tempsum < sum)
            high++;
        else
            low++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int sum;
    vector<vector<int> > res;
    vector<int> temp;
    cin >> sum;
    res = FindContinuousSequence(sum);
    vector<vector<int> >::iterator iter;
    vector<int>::iterator it;
    for (iter = res.begin(); iter != res.end(); iter++) {
        temp = *iter;
        for (it = temp.begin(); it != temp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}

/*
 * History:
 *  2023.1.4 : first version
 */

#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int>& arr)
{
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    int getNumBits(int n)
    {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    vector<int> countBits(int n)
    {
        vector<int> res(n+1, 0);
        for (int i = 0; i <= n; i++) {
            res[i] = getNumBits(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> res1 = sol.countBits(2);
    printVec(res1);
    vector<int> res2 = sol.countBits(5);
    printVec(res2);

    return 0;
}
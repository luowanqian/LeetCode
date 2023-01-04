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
        int mask = 0x1;
        for (int i = 1; i < sizeof(int)*8; i++) {
            int tmp = n & mask;
            if (tmp != 0) {
                count++;
            }
            mask = mask << 1;
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
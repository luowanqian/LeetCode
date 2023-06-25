/*
 * LeetCode 547. Number of Provinces
 * History:
 *  2023.6.25 : first version
 */

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int FindCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        dsMap.resize(n, 0);
        for (int i = 0; i < n; i++) {
            dsMap[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    Merge(i, j);
                }
            }
        }

        unordered_set<int> uniques;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x = Find(i);
            if (uniques.count(x) == 0) {
                res++;
                uniques.insert(x);
            }
        }

        return res;
    }

    int Find(int x)
    {
        return dsMap[x] == x ? x : Find(dsMap[x]);
    }

    void Merge(int x, int y)
    {
        dsMap[Find(x)] =  Find(y);
    }

private:
    vector<int> dsMap;
};

int main()
{
    vector<vector<int>> connects1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    int count1 = sol.FindCircleNum(connects1);
    cout << count1 << endl;

    return 0;
}
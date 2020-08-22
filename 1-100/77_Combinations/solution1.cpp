/*
 * 2020-08-21
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;

        back_tracking(res, n, k, 1, subset);

        return res;
    }

    void back_tracking(vector<vector<int>>& combinations, int n, int k, int start, vector<int>& subset) {
        if (subset.size() == k) {
            combinations.push_back(subset);
            return;
        }
        for (int i=start; i<=n; i++) {
            if (subset.size() < k)
                subset.push_back(i);
                back_tracking(combinations, n, k, i+1, subset);
                subset.pop_back();
        }
    }
};

int main()
{
    int n = 4;
    int k = 2;
    Solution solu;
    vector<vector<int>> res = solu.combine(n, k);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
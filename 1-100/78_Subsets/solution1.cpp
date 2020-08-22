/*
 * 2020-08-21
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> sub;
        back_tracking(subsets, 0, sub, nums);
        return subsets;
    }

    void back_tracking(vector<vector<int>>& subsets, int start, vector<int>& sub, vector<int>& nums) {
        subsets.push_back(sub);
        // iterate all possible candidates
        for (int i=start; i<nums.size(); i++) {
            // try this partial candidate solution
            sub.push_back(nums[i]);
            // given the candidate, explore further
            back_tracking(subsets, i+1, sub, nums);
            // backtrack
            sub.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solu;
    vector<vector<int>> res = solu.subsets(nums);
    for (int i=0; i<res.size(); i++) {
        cout << "[";
        for (int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

/*
 * 2020-08-15
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void find_permutations(vector<vector<int>>& permutations, int start, vector<int>& nums) {
        if (start >= nums.size()) {
            permutations.push_back(nums);
        } else {
            // permute num[begin..end]
            // num[0..begin-1] have been fixed/permuted
            for (int i=start; i<nums.size(); i++) {
                swap(nums[i], nums[start]);
                find_permutations(permutations, start+1, nums);
                swap(nums[i], nums[start]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;

        find_permutations(permutations, 0, nums);

        return permutations;
    }
};

int main()
{
    vector<int> nums = {0, -1, 1};
    Solution solu;
    vector<vector<int>> permutations = solu.permute(nums);
    for (int i=0; i<permutations.size(); i++) {
        for (int j=0; j<permutations[i].size(); j++) {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
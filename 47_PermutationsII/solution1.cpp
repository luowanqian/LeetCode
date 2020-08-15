/*
 * 2020-08-15
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void find_permutation(vector<vector<int>>& permutations, int begin, vector<int>& nums) {
        if (begin >= nums.size()) {
            permutations.push_back(nums);
        } else {
            unordered_map<int, int> unique;
            for (int i=begin; i<nums.size(); i++) {
                if (unique.find(nums[i]) != unique.end())
                    continue;
                unique.insert(make_pair(nums[i], 1));
                swap(nums[begin], nums[i]);
                find_permutation(permutations, begin+1, nums);
                swap(nums[begin], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;

        find_permutation(permutations, 0, nums);

        return permutations;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    Solution solu;
    vector<vector<int>> permutations = solu.permuteUnique(nums);
    for (int i=0; i<permutations.size(); i++) {
        for (int j=0; j<permutations[i].size(); j++) {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

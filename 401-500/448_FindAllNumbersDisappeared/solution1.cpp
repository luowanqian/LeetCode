/*
 * LeetCode 448. Find All Numbers Disappeared in an Array
 * History:
 *  2023.1.7 : first version
 */

#include "Print.h"
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> unique;

        for (auto& x : nums) {
            unique.insert(x);
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!unique.count(i)) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 { 4, 3, 2, 7, 8, 2, 3, 1 };
    vector<int> res1 = sol.findDisappearedNumbers(nums1);
    printVector(res1);

    return 0;
}
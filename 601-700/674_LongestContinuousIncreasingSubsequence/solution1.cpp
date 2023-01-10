/*
 * LeetCode 674. Longest Continuous Increasing Subsequence
 * History:
 *  2023.1.10 : first version
 */

#include "Print.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int l = 0;
        int h = 1;
        // 区间[l, h)内元素都是递增的 
        for (h = 1; h < nums.size(); h++) {
            // 遇到下一个元素递减，则更新区间位置
            if (nums[h] <= nums[h-1]) {
                res = max(res, h - l);
                l = h;
            }
        }
        res = max(res, h - l);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 {1,3,5,4,7};
    cout << sol.findLengthOfLCIS(nums1) << endl;
    vector<int> nums2 {2,2,2,2,2};
    cout << sol.findLengthOfLCIS(nums2) << endl;
    vector<int> nums3 {1,3,5,7};
    cout << sol.findLengthOfLCIS(nums3) << endl;

    return 0;
}
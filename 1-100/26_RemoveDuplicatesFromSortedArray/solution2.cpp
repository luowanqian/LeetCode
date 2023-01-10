/*
 * LeetCode 26. Remove Duplicates from Sorted Array
 * History:
 *  2023.1.10 : first version
 */

#include "Print.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        int pre = nums[0];
        // 区间[0, j)内元素不重复
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != pre) {
                pre = nums[i];
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 {0,0,1,1,1,2,2,3,3,4};
    cout << sol.removeDuplicates(nums1) << endl;
    printVector(nums1);
    
    return 0;
}
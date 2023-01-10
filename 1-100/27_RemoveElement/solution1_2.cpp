/*
 * LeetCode 27. Remove Element
 * History:
 *  2023.1.10 : first version
 */

#include "Print.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        // 区间内 [0, j) 都是无目标数字val
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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
    vector<int> nums1 {0,1,2,2,3,0,4,2};
    int val1 = 3;
    cout << sol.removeElement(nums1, val1) << endl;
    printVector(nums1);

    return 0;
}
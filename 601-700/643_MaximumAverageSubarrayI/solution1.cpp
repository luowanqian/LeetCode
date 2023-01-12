/*
 * LeetCode 643. Maximum Average Subarray I
 * History:
 *  2023.1.12 : first version
 */

#include "Print.h"
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max = 0;
        int total = 0;

        // calculate first k
        for (int i = 0; i < k; i++) {
            max += nums[i];
        }
        total = max;

        int low = 0;
        int high = k-1;
        while (high < nums.size()-1) {
            total -= nums[low];
            total += nums[high+1];
            if (total > max) {
                max = total;
            }
            low++;
            high++;
        }

        return (double)max / k;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 {1,12,-5,-6,50,3};
    printVector(nums1);
    cout << sol.findMaxAverage(nums1, 4) << endl;

    vector<int> nums2 {5};
    printVector(nums2);
    cout << sol.findMaxAverage(nums2, 1) << endl;

    return 0;
}
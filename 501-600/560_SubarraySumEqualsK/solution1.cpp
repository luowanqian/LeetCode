/*
 * LeetCode 560. Subarray Sum Equals K
 * History:
 *  2023.1.9 : first version
 */

#include "Print.h"
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSums(nums.size(), 0);

        // calculate prefix sum of array
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSums[i] = prefixSums[i-1] + nums[i];
        }

        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (prefixSums[i] == k) {
                count++;
            }
            int res = prefixSums[i] - k;
            if (map.count(res)) {
                count += map[res];
            }
            map[prefixSums[i]] += 1;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 {1, 2, 3};
    printVector(nums1);
    // expected: 2
    // [1, 2], [3]
    cout << "Res: " << sol.subarraySum(nums1, 3) << endl;

    // corner case
    vector<int> nums2 {1, -1, 0};
    printVector(nums2);
    // expected: 3
    // [1, -1, 0], [0], [1, -1]
    cout << "Res: " << sol.subarraySum(nums2, 0) << endl;

    // corner case
    vector<int> nums3 {0, 0, 4};
    printVector(nums3);
    // expected: 3
    // [0, 0, 4], [0, 4], [4]
    cout << "Res: " << sol.subarraySum(nums3, 4) << endl;

    return 0;
}
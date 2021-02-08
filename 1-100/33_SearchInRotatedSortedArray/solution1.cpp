//
// Created by 罗万千 on 2021/2/8.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int bound = 0;
        int n = nums.size();

        for (int i=1; i<n; i++) {
            if (nums[i] < nums[i-1]) {
                bound = i;
                break;
            }
        }

        int low, mid, realMid, high;

        low = 0;
        high = n - 1;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            realMid = (mid + bound) % n;

            if (nums[realMid] > target)
                high = mid - 1;
            else if (nums[realMid] < target)
                low = mid + 1;
            else
                return realMid;
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;
    Solution sol;
    cout << sol.search(nums, target) << endl;
    return 0;
}
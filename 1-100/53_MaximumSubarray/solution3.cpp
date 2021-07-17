/*
 * dp[0] = nums[0]
 * dp[i] = max{dp[i-1], nums[i]} i=1,2,...
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        vector<int> dp(nums.size()+1, 0);

        dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            if (res < dp[i])
                res = dp[i];
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution solu;
    cout << solu.maxSubArray(nums) << endl;
    return 0;
}
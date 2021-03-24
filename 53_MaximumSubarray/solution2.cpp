//
// Created by 罗万千 on 2021/3/24.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * f(i) = max{ f(i-1) + a[i], a[i] }
 * res = max_{1<=i<=n} {f(i)}
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int maxSum = nums[0];
        int currentSum = nums[0];
        int sum;

        for (int i=1; i<nums.size(); i++) {
            sum = currentSum + nums[i];
            if (sum >= nums[i]) {
                currentSum = sum;
            } else {
                currentSum = nums[i];
            }
            if (currentSum > maxSum)
                maxSum = currentSum;
        }

        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solu;
    cout << solu.maxSubArray(nums);
    return 0;
}

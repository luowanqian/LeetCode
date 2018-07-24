#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum, largest_sum;

        current_sum = 0;
        largest_sum = 0x80000000;
        for (int i=0; i<nums.size(); i++) {
            if (i == 0 || current_sum <= 0)
                current_sum = nums[i];
            else
                current_sum += nums[i];

            if (current_sum > largest_sum)
                largest_sum = current_sum;
        }

        return largest_sum;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int largest_sum = solu.maxSubArray(nums);

    cout << largest_sum << endl;

    return 0;
}

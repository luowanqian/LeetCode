#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int max_product;
        int current_min, current_max;
        int tmp1, tmp2;

        max_product = 0x80000000;
        for (int i=0; i<nums.size(); i++) {
            if (i == 0) {
                current_min = current_max = nums[i];
            } else {
                tmp1 = current_min * nums[i];
                tmp2 = current_max * nums[i];
                current_min = min(min(tmp1, tmp2), nums[i]);
                current_max = max(max(tmp1, tmp2), nums[i]);
            }

            max_product = max(current_max, max_product);
        }

        return max_product;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    Solution solu;
    cout << solu.maxProduct(nums) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int times;
        int current_reach;
        int current_max = 0;

        times = 0;
        current_reach = 0;
        for (int i=0; i<nums.size(); i++) {
            if (current_reach < i) {
                current_reach = current_max;
                times++;
            }

            current_max = max(current_max, nums[i] + i);
        }

        return times;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 2, 2, 0, 4};
    Solution solu;
    cout << solu.jump(nums) << endl;

    return 0;
}

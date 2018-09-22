#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2.0;
            if (nums[mid] < nums[mid+1])
                return find(nums, mid+1, right);
            else
                return find(nums, left, mid);
        } else {
            return left;
        }
    }

    int findPeakElement(vector<int>& nums) {
        return find(nums, 0, nums.size()-1);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;

    cout << sol.findPeakElement(nums) << endl;

    return 0;
}

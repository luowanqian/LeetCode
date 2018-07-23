#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right, int target) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                return binary_search(nums, mid+1, right, target);
            else
                return binary_search(nums, left, mid-1, target);
        }

        return left;
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        return binary_search(nums, 0, nums.size()-1, target);
    }
};


int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;

    Solution solu;
    cout << solu.searchInsert(nums, target) << endl;

    return 0;
}

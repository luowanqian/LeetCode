#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left, right, mid;

        left = 0;
        mid = 0;
        right = nums.size()-1;
        while (left < right) {
            mid = left + (right-left)/2.0;
            if (nums[mid] < nums[mid+1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;

    cout << sol.findPeakElement(nums) << endl;

    return 0;
}


/*
 * History:
 *  2023.1.4 : first version
 */

#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int>& nums)
{
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t i = 0, j = 1;
        size_t len = nums.size();
        while (j < len) {
            if (nums[i] != 0) {
                i++;
                j++;
            } else if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else {
                j++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 { 0, 1, 0, 3, 12 };
    sol.moveZeroes(nums1);
    printVec(nums1);

    vector<int> nums2 { 2, 4, 3, 0, 0};
    sol.moveZeroes(nums2);
    printVec(nums2);

    return 0;
}
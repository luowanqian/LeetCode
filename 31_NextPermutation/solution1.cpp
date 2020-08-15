/*
 * 2020-08-15
 * Algorithm: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k, l, temp, n;

        n = nums.size();
        // find the largest index k such that a[k] < a[k + 1]
        for (k=n-2; k>=0; k--) {
            if (nums[k] < nums[k+1])
                break;
        }
        if (k < 0) {
            // if no such index exists, reverse array a
            reverse(nums.begin(), nums.end());
        } else {
            // find the largest index l greater than k such that a[k] < a[l]
            for (l=n-1; l>k; l--) {
                if (nums[k] < nums[l])
                    break;
            }
            // swap a[k] and a[l]
            temp = nums[l];
            nums[l] = nums[k];
            nums[k] = temp;
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

int main()
{
    vector<int> nums = {1, 3, 2};
    Solution solu;

    for (int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    solu.nextPermutation(nums);

    for (int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
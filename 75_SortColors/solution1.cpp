#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution solu;

    for (auto i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    solu.sortColors(nums);

    for (auto i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
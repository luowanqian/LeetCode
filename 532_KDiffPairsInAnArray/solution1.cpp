#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int num;
        unordered_set<int> pair_smalls;
        unordered_set<int> unique_nums;
        for (int i=0; i<nums.size(); i++) {
            num = nums[i];
            if (unique_nums.find(num - k) != unique_nums.end())
                pair_smalls.insert(num - k);
            if (unique_nums.find(num + k) != unique_nums.end())
                pair_smalls.insert(num);

            unique_nums.insert(num);
        }

        return pair_smalls.size();
    }
};

int main()
{
    Solution solu;

    vector<int> nums1 = {3, 1, 4, 1, 5};
    int k1 = 2;
    cout << solu.findPairs(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = -1;
    cout << solu.findPairs(nums2, k2) << endl;

    return 0;
}



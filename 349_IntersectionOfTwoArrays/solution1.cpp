#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> unique_nums1;
        for (auto it=nums1.begin(); it!=nums1.end(); it++)
            unique_nums1.insert(*it);

        unordered_set<int> unique_nums;
        for (auto it=nums2.begin(); it!=nums2.end(); it++) {
            if (unique_nums1.find(*it) != unique_nums1.end())
                unique_nums.insert(*it);
        }

        vector<int> ret;
        for (auto it=unique_nums.begin(); it!=unique_nums.end(); it++)
            ret.push_back(*it);

        return ret;
    }
};

int main()
{
    Solution solu;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ret = solu.intersection(nums1, nums2);

    for (auto it=ret.begin(); it!=ret.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}

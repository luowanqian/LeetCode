/*
 * 2020-08-22
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        if (nums1.empty() || nums2.empty())
            return res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int p1, p2;
        int last_equal = INT_MAX;
        p1 = p2 = 0;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                if (nums1[p1] != last_equal)
                    res.push_back(nums1[p1]);
                last_equal = nums1[p1];
                p1++;
                p2++;
            } else if (nums1[p1] < nums2[p2]) {
                p1++;
            } else {
                p2++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    Solution solu;
    vector<int> res = solu.intersection(nums1, nums2);
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        if (nums1.size() == 0)
            return ret;
        else if (nums2.size() == 0)
            return ret;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int p1, p2, repeat;
        p1 = p2 = 0;
        repeat = nums1[0] < nums2[0] ? nums1[0] - 1 : nums2[0] - 1;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                p1++;
            } else if (nums1[p1] > nums2[p2]) {
                p2++;
            } else {
                if (repeat != nums1[p1])
                    ret.push_back(nums1[p1]);
                repeat = nums1[p1];
                p1++;
                p2++;
            }
        }

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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return vector<int>();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ret;
        int i, j;

        i = 0;
        j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                ret.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution solu;
    vector<int> insection = solu.intersect(nums1, nums2);
    for (auto it=insection.begin(); it!=insection.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}

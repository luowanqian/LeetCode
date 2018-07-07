#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty() || nums2.empty())
            return vector<int>();

        vector<int> ret;
        unordered_map<int, int> counts;

        for (auto elem : nums1)
            counts[elem]++;

        for (auto elem : nums2) {
            if (counts.find(elem) != counts.end()) {
                if (counts[elem] > 0)
                    ret.push_back(elem);
                else
                    counts.erase(elem);
                counts[elem]--;
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

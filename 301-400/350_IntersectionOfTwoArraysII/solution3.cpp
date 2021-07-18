#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> num_count;
        for (int i : nums1) {
            num_count[i]++;
        }
        for (int i : nums2) {
            if (num_count.count(i)) {
                if (num_count[i] > 0) {
                    res.push_back(i);
                    num_count[i]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution solu;

    vector<int> res = solu.intersect(nums1, nums2);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
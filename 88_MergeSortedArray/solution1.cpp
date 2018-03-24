//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (m <= 0)
            nums1 = nums2;
        if (n <= 0)
            return;

        int p, p1, p2;
        p1 = m - 1;
        p2 = n - 1;
        p = m + n - 1;

        while (p >= 0 && p1 >= 0 && p2 >= 0) {
            if (nums1[p1] >= nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else if (nums1[p1] < nums2[p2]) {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        if (p2 >= 0) {
            while (p >=0 && p2 >=0)
                nums1[p--] = nums2[p2--];
        }
    }
};

int main()
{
    Solution solu;

    vector<int> nums1 = {1, 3, 5, 7, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    solu.merge(nums1, 4, nums2, nums2.size());

    for (auto it=nums1.begin(); it!=nums1.end(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int> nums3 = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    vector<int> nums4 = {-1, 1, 1, 1, 2, 3};
    solu.merge(nums3, 3, nums4, nums4.size());

    for (auto it=nums3.begin(); it!=nums3.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
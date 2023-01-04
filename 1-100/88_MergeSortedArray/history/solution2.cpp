/*
 * 2020-08-13
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos, pos1, pos2;

        pos = nums1.size() - 1;
        pos1 = m - 1;
        pos2 = n - 1;

        while (pos1 >= 0 || pos2 >= 0) {
            if (pos2 < 0)
                break;
            if (pos1 >= 0 && nums1[pos1] > nums2[pos2]) {
                nums1[pos] = nums1[pos1];
                pos1--;
            } else {
                nums1[pos] = nums2[pos2];
                pos2--;
            }
            pos--;
        }
    }
};

int main()
{
    int m = 3, n = 3;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    Solution solu;
    solu.merge(nums1, m, nums2, n);

    for (int i=0; i<nums1.size(); i++)
        cout << nums1[i] << " ";
    cout << endl;

    return 0;
}


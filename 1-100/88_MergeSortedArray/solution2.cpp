#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, pos;
        i = m - 1;
        j = n - 1;
        pos = m + n - 1;
        while (pos >= 0) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] >= nums2[j])
                    nums1[pos--] = nums1[i--];
                else
                    nums1[pos--] = nums2[j--];
            } else if (i >= 0) {
                nums1[pos--] = nums1[i--];
            } else {
                nums1[pos--] = nums2[j--];
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    Solution solu;

    solu.merge(nums1, m, nums2, n);
    for (int i : nums1)
        cout << i << " ";
    cout << endl;

    return 0;
}

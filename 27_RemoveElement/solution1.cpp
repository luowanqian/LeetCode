#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos, len;

        len = 0;
        pos = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                len++;
                nums[++pos] = nums[i];
            }
        }

        return len;
    }
};

int main()
{
    int val = 2;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    Solution solu;
    int len = solu.removeElement(nums, val);
    for (int i=0; i<len; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}

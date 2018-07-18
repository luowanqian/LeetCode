#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int len, pos;

        len = 1;
        pos = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[pos]) {
                len++;
                nums[++pos] = nums[i];
            }
        }

        return len;
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solu;
    int len = solu.removeDuplicates(nums);
    for (int i=0; i<len; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}

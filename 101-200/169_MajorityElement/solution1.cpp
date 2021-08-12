#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int limit = nums.size() / 2;
        sort(nums.begin(), nums.end());
        int n = nums[0];
        int count = 1;
        for (int i=1; i<nums.size(); i++) {
            if (n == nums[i]) {
                count++;
            } else {
                n = nums[i];
                count = 1;
            }
            if (count > limit)
                break;
        }
        return n;
    }
};

int main()
{
    return 0;
}
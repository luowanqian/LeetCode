#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for (int n : nums) {
            if (dup.count(n))
                return true;
            dup.insert(n);
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    Solution solu;
    cout << solu.containsDuplicate(nums) << endl;
    return 0;
}
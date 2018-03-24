//
// 使用 unordered_map 实现，底层是哈希表
//

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        unordered_map<int, int>::const_iterator iter;
        vector<int> indices;
        for (int i=0; i<nums.size(); i++) {
            if ((iter = nums_map.find(target - nums[i])) == nums_map.end()) {
                nums_map.insert(make_pair(nums[i], i));
            } else {
                indices.push_back(iter->second);
                indices.push_back(i);
                break;
            }
        }

        return indices;
    }
};

int main()
{
    int target = 9;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    Solution sol;
    vector<int> indices = sol.twoSum(nums, target);
    if (indices.size() == 0) {
        cout << "Not found" << endl;
    } else {
        cout << "Find: [" << indices[0] << ", " << indices[1] << "]" << endl;
    }
    return 0;
}

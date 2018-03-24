//
// 使用map进行实现，底层是红黑树
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> indices;
            map<int, int> tmp;
            map<int, int>::iterator iter;
            int num;
            for (vector<int>::size_type i=0; i!=nums.size(); i++) {
                num = nums[i];
                if ((iter = tmp.find(target-num)) == tmp.end()) {
                    tmp.insert(make_pair(num, i));
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

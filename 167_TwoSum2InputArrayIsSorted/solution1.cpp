#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> idx;

        if (numbers.size() < 2)
            return idx;

        int left, right;
        left = 0;
        right = numbers.size()-1;
        while (left < right) {
            if (numbers[left] + numbers[right] < target) {
                left++;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else {
                idx.push_back(left+1);
                idx.push_back(right+1);
                break;
            }
        }

        return idx;
    }
};

int main()
{
    Solution solu;
    vector<int> nums {2, 7, 11, 15};
    int target = 9;
    vector<int> idx = solu.twoSum(nums, target);
    if (idx.size() < 2)
        cout << "Not found" << endl;
    else
        cout << "index1=" << idx[0]
             << ", index2=" << idx[1] << endl;

    return 0;
}

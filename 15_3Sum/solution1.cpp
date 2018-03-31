#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> triplets;

        if (nums.size() < 3)
            return triplets;

        sort(nums.begin(), nums.end());
        int left, right, target;
        for (int i=0; i<nums.size(); i++) {
            if (i == 0 || nums[i] > nums[i-1]) {
                target = -nums[i];
                left = i+1;
                right = nums.size()-1;
                while (left < right) {
                    if (nums[left] + nums[right] < target) {
                        left++;
                    } else if (nums[left] + nums[right] > target) {
                        right--;
                    } else {
                        triplets.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left-1])
                            left++;
                        while (left < right && nums[right] == nums[right+1])
                            right--;
                    }
                }
            }
        }

        return triplets;
    }
};

int main()
{
    Solution solu;
    //vector<int> nums {1,0,1,2,-1,-4};
    vector<int> nums {0,-5,3,-4,1,3,-4,-2,-2,-2,0,3,0,1,-4,-2,0};

    vector<vector<int>> triplets = solu.threeSum(nums);
    for (int i=0; i<triplets.size(); i++) {
        for (int j=0; j<triplets[i].size(); j++) {
            cout << triplets[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

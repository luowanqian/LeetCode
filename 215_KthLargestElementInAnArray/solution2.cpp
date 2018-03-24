//
// 使用最小堆
//


#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> k_numbers;
        int min_number;

        for (auto it=nums.begin(); it!=nums.end(); ++it) {
            if (k_numbers.size() < k) {
                k_numbers.push(*it);
            } else {
                min_number = k_numbers.top();
                if (*it > min_number) {
                    k_numbers.pop();
                    k_numbers.push(*it);
                }
            }
        }

        return k_numbers.top();
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout << "The 2th max number is " << solu.findKthLargest(nums, 2) << endl;

    return 0;
}
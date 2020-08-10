/*
 * My Solution
 * 2020-08-10
 */

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i=0; i<nums.size(); i++) {
            int x = nums[i];
            if (min_heap.size() < k) {
                min_heap.push(x);
            } else {
                int top = min_heap.top();
                if (top < x) {
                    min_heap.pop();
                    min_heap.push(x);
                }
            }
        }
        return min_heap.top();
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution solu;
    cout << solu.findKthLargest(nums, k);

    return 0;
}

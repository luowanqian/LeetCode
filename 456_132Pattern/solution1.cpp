/*
 * 2020-08-11
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int prev = INT_MIN;
        for (int i=nums.size()-1; i>=0; i--) {
            while (!st.empty() && nums[i] > st.top()) {
                if (prev > st.top())
                    return true;
                prev = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return !st.empty() && prev > st.top();
    }
};

int main()
{
    vector<int> nums = {3, 1, 4, 2};
    Solution solu;
    cout << solu.find132pattern(nums) << endl;

    return 0;
}
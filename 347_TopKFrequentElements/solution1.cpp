/*
 * 2020-08-10
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> top_freq;
        for (int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto it=freq.begin(); it!=freq.end(); ++it) {
            top_freq.push(pair<int, int>(it->second, it->first));
        }
        int count = 0;
        while (!top_freq.empty()) {
            count++;
            if (count > k)
                break;
            auto top = top_freq.top();
            ret.push_back(top.second);
            top_freq.pop();
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    int k = 2;
    Solution solu;
    vector<int> top_freq = solu.topKFrequent(nums, k);
    for (int i=0; i<top_freq.size(); i++) {
        cout << top_freq[i] << " ";
    }
    cout << endl;

    return 0;
}
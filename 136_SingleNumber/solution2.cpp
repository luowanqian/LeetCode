#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;

        unordered_map<int, int> counts;
        for (auto it=nums.begin(); it!=nums.end(); ++it) {
            counts[*it]++;
        }

        for (auto it=counts.begin(); it!=counts.end(); ++it) {
            if (it->second == 1)
                return it->first;
        }

        return 0;
    }
};

int main()
{
    Solution solu;

    vector<int> v1 = {2, 3, 2, -1, 3};
    cout << "Single Number is: " << solu.singleNumber(v1) << endl;

    return 0;
}

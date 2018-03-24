//
// Created by 罗万千 on 18/3/11.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto it=nums.begin(); it!=nums.end(); ++it)
            ret ^= *it;

        return ret;
    }
};

int main()
{
    Solution solu;

    vector<int> v1 = {2, 3, 2, -1, 3};
    cout << "Single Number is: " << solu.singleNumber(v1) << endl;

    return 0;
}


//
// 使用红黑树
//

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> k_numbers;
        multiset<int>::iterator set_iterator;

        for (auto it=nums.begin(); it!=nums.end(); ++it) {
            if (k_numbers.size() < k) {
                k_numbers.insert(*it);
            } else {
                set_iterator = k_numbers.begin();
                if (*it > *set_iterator) {
                    k_numbers.erase(set_iterator);
                    k_numbers.insert(*it);
                }
            }
        }

        return *(k_numbers.begin());
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout << "The 2th max number is " << solu.findKthLargest(nums, 2) << endl;

    return 0;
}

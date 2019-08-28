/*
 * Time Complexity: O(N), where N is the length of array.
 * Space Complexity: O(N).
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.size() == 0)
            return vector<int>();

        vector<int> ret(A.size());
        size_t odd, even;

        odd = even = 0;
        for (auto it=A.begin(); it!=A.end(); it++) {
            if (*it % 2 == 0) {
                ret[2 * even] = *it;
                even++;
            } else {
                ret[2 * odd + 1] = *it;
                odd++;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> A = {4, 2, 5, 7};
    Solution solution;
    vector<int> ret = solution.sortArrayByParityII(A);
    for (auto it=ret.begin(); it!=ret.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}

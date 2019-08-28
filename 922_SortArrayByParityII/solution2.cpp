/*
 * Time Complexity: O(N), where N is the length of array.
 * Space Complexity: O(1).
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        size_t i, j;
        int tmp;

        j = 1;
        for (i=0; i<A.size(); i=i+2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1)
                    j = j + 2;

                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }

        return A;
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


/*
 * LeetCode 461. Hamming Distance
 * History:
 *  2023.1.6 : first version
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while (z > 0) {
            z = z & (z - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingDistance(1, 4) << endl;
    cout << sol.hammingDistance(3, 1) << endl;
    return 0;
}
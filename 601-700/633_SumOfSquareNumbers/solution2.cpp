/*
 * Two pointers
 */

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        long long sum;

        while (left <= right) {
            sum = left*left + right*right;
            if (sum > c)
                right--;
            else if (sum < c)
                left++;
            else
                return true;
        }

        return false;
    }
};

int main()
{
    Solution solu;
    int c = 10;
    cout << solu.judgeSquareSum(c) << endl;

    return 0;
}
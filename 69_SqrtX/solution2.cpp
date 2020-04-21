/*
 * Use binary search to find the square root of x
 */

#include <iostream>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        long long low, high, mid, square;

        // search in [low, high), so high = x + 1
        // use casting to avoid numerical overflow
        low = 0, high = (long long)x + 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            square = mid * mid;
            if (square <= x)
                low = mid + 1;
            else
                high = mid;
        }
        return low - 1;
    }
};

int main()
{
    int x = 2147483647;
    Solution solu;

    cout << "Sqrt(" << x << ") = " << solu.mySqrt(x) << endl;
    return 0;
}
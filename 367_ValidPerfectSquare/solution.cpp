#include <iostream>
using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low, mid, high;

        low = 0;
        high = (long)num + 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (mid * mid < num)
                low = mid + 1;
            else
                high = mid;
        }

        // if it doesn't find square of number
        if (low * low != num)
            return false;

        return true;
    }
};


int main()
{
    int num;
    Solution solu;

    // max of int
    // num = 2147483647;
    num = 14;
    cout << num << " is perfect square: "
         << solu.isPerfectSquare(num) << endl;
    return 0;
}

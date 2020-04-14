#include <iostream>
#include <limits>
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        long quotient;
        long big_dividend, big_divisor;
        bool negative = false;

        if (dividend == numeric_limits<int>::min() && divisor == -1)
            return numeric_limits<int>::max();

        if ((dividend ^ divisor) < 0)
            negative = true;

        big_dividend = dividend;
        big_divisor = divisor;
        if (big_dividend < 0)
            big_dividend = -big_dividend;
        if (big_divisor < 0)
            big_divisor = -big_divisor;

        quotient = 0;
        for (int i=31; i>=0; i--) {
            if ((big_dividend >> i) >= big_divisor) {
                quotient += 1 << i;
                big_dividend -= big_divisor << i;
            }
        }

        if (negative)
            quotient = -quotient;
        return quotient;
    }
};


int main()
{
    int dividend, divisor;

    dividend = 10;
    divisor = -2;

    Solution solu;
    cout << solu.divide(dividend, divisor) << endl;

    return 0;
}

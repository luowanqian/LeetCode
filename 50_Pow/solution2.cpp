#include <iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        long long num = n;
        double ans;

        if (n < 0) {
            // use long long type to avoid numerical overflow
            num = -(long long)n;
            x = 1 / x;
        }

        ans = 1.0;
        while (num > 0) {
            if ((num & 1) != 0)
                ans *= x;
            x *= x;
            num >>= 1;
        }

        return ans;
    }
};

int main()
{
    double x;
    int n;
    Solution solu;

    x = 1.00000;
    n = -2147483648;    // n = -2^31
    cout << "Pow(" << x << ", " << n << ") = "
         << solu.myPow(x, n) << endl;
    return 0;
}

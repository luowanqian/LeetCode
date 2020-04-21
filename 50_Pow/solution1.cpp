#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // do not transfer n to -n if n < 0
        // because of numerical overflow (n = -2^31)
        if (n == 0)
            return 1.0;
        double half = myPow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            if (n < 0)
                x = 1 / x;
            return half * half * x;
        }
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

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long low, high, mid;

        low = 0;
        high = x;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

int main()
{
    int x = 2147395599;
    Solution solu;

    cout << "Sqrt of " << x << ": "
         << solu.mySqrt(x) << endl;
    return 0;
}

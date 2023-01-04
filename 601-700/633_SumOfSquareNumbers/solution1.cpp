#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrt_c = int(sqrt(c));
        for (int a=0; a<=sqrt_c; a++) {
            double sqrt_res = sqrt(c - a*a);
            if (sqrt_res == int(sqrt_res))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solu;
    int c = 3;
    cout << solu.judgeSquareSum(c) << endl;

    return 0;
}
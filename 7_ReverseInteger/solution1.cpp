#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int mod;
        long long num;
        bool postive;

        num = 0;
        postive = x >=0 ? true : false;
        while (x) {
            mod = x % 10;
            x = x / 10;
            num = num * 10 + mod;
            if ((postive && num > 0x7FFFFFFF)
                || (!postive && num < (signed int)0x80000000))
                return 0;
        }

        return num;
    }
};

int main()
{
    int x = 120;

    Solution solu;
    cout << "Revert: " << solu.reverse(x) << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int origin, revert, mod;

        origin = x;
        revert = 0;
        while (x) {
            mod = x % 10;
            revert = revert * 10 + mod;
            x = x / 10;
        }

        return revert == origin;
    }
};

int main()
{
    int x = 121;
    Solution solu;

    cout << solu.isPalindrome(x) << endl;

    return 0;
}

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        int num_ways = 0;
        int a1 = 1, a2 = 2;

        for (int i=3; i<=n; i++) {
            num_ways = a1 + a2;
            a1 = a2;
            a2 = num_ways;
        }

        return num_ways;
    }
};

int main()
{
    Solution solu;

    int n1 = 4;
    cout << solu.climbStairs(n1) << endl;

    int n2 = 10;
    cout << solu.climbStairs(n2) << endl;
    return 0;
}

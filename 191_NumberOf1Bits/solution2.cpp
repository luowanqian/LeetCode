#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int num_bits;

        num_bits = 0;
        while (n) {
            if (n & 1)
                num_bits++;
            n = n >> 1;
        }

        return num_bits;
    }
};

int main()
{
    uint32_t n = 11;
    Solution solu;

    cout << n << ": " << solu.hammingWeight(n)
         << " bits" << endl;
    return 0;
}

#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int num_bits;
        uint32_t flag;

        num_bits = 0;
        flag = 1;
        for (int i=0; i<32; i++) {
            if (flag & n)
                num_bits++;
            flag = flag << 1;
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

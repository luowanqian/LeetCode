#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};

        vector<double> coef;    // store 0!, 1!, ...
        vector<int> ret(rowIndex+1);

        coef.push_back(1);  // 0!
        coef.push_back(1);  // 1!
        for (int i=2; i<=rowIndex/2; i++)
            coef.push_back(coef[i-1]*i);

        ret[0] = 1;     // C_n^0
        for (int i=1; i<=rowIndex; i++) {
            if (i <= rowIndex/2) {
                ret[i] = ((double)ret[i-1])*(rowIndex-i+1)/i;
            } else {
                ret[i] = ret[rowIndex-i];
            }
        }

        return ret;
    }
};

int main()
{
    int row_idx = 33;
    Solution solu;
    vector<int> ret;

    ret = solu.getRow(row_idx);

    for (int i=0; i<ret.size(); i++)
        cout << ret[i] << " ";
    cout << endl;

    return 0;
}

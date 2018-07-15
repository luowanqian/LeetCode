#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string ret = s;
        int n, pos, times;

        n = 0;
        times = 0;
        for (int i=0; i<numRows; i++) {
            pos = i;
            times = 0;
            while (pos < s.size()) {
                ret[n++] = s[pos];
                if (i == 0 || i == numRows-1) {
                    pos = pos + (numRows - 1) * 2;
                } else {
                    if (times % 2 == 0)
                        pos = pos + (numRows - 1 - i) * 2;
                    else
                        pos = pos + i * 2;
                    times++;
                }
            }
        }

        return ret;
    }
};

int main()
{
    string str = "PAYPALISHIRING";
    Solution solu;
    cout << "Convert: " << solu.convert(str, 3);

    return 0;
}
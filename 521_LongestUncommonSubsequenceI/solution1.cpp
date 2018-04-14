#include <iostream>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b)
    {
        int i = 0, j = 0;

        if (a.size() == b.size()) {
            while (i < a.size() && j < a.size() && a[i] == b[j]) {
                i++;
                j++;
            }
            if (i < a.size() || j < b.size())
                return a.size();
            else
                return -1;
        } else {
            return a.size() > b.size() ? a.size() : b.size();
        }
    }
};

int main()
{
    Solution solu;
    string str1 = "abcd", str2 = "abc";

    cout << solu.findLUSlength(str1, str2) << endl;

    return 0;
}
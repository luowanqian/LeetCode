#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s)
    {
        vector<int> trans;
        int num_bs = 0;
        int count;

        count = 0;
        for (int i=0; i<s.size(); i++) {
            count++;
            if (i+1 < s.size() && s[i] != s[i+1]) {
                trans.push_back(count);
                count = 0;
                continue;
            }
        }
        if (count > 0)
            trans.push_back(count);

        for (int i=0; i<trans.size()-1; i++)
            num_bs += trans[i] > trans[i+1] ? trans[i+1] : trans[i];

        return num_bs;
    }
};

int main()
{
    Solution solu;

    string str1 = "00110011";
    cout << str1 << ": " << solu.countBinarySubstrings(str1) << endl;

    string str2 = "10101";
    cout << str2 << ": " << solu.countBinarySubstrings(str2) << endl;

    return 0;
}

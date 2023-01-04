#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s)
    {
        if (s.size() == 0)
            return -1;
        else if (s.size() == 1)
            return 0;

        /* letters[i]
         * -1 means letter repeat
         * 0 means letter not appear
         * > 0 means position of letter in string (index starts from 1)
         */
        int letters[26];
        int pos;

        memset(letters, 0, sizeof(letters));
        for (int i=0; i<s.size(); i++) {
            pos = s[i] - 'a';
            if (letters[pos] > 0)
                letters[pos] = -1;
            else if (letters[pos] == 0)
                letters[pos] = i + 1;
        }

        int ret = -1;
        for (int i=0; i<26; i++) {
            if (letters[i] > 0) {
                if (ret == -1)
                    ret = letters[i] - 1;
                else if (ret > letters[i] - 1)
                    ret = letters[i] - 1;
            }
        }

        return ret;
    }
};

int main()
{
    Solution solu;

    string str1 = "aadadaad";
    cout << str1 << ": " << solu.firstUniqChar(str1) << endl;

    string str2 = "loveleetcode";
    cout << str2 << ": " << solu.firstUniqChar(str2) << endl;

    return 0;
}
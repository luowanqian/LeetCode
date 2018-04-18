#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;

        int rmap[26], mmap[26];

        memset(rmap, 0, sizeof(rmap));
        memset(mmap, 0, sizeof(mmap));

        int i = 0, j = 0;
        while (i < ransomNote.size() || j < magazine.size()) {
            if (i < ransomNote.size())
                rmap[ransomNote[i++] - 'a'] += 1;
            if (j < magazine.size())
                mmap[magazine[j++] - 'a'] += 1;
        }

        for (i=0; i<26; i++)
            if (rmap[i] > mmap[i])
                return false;

        return true;
    }
};

int main()
{
    Solution solu;

    string r1 = "ab";
    string m1 = "aba";
    cout << r1 << " " << m1 << ": " << solu.canConstruct(r1, m1);

    return 0;
}
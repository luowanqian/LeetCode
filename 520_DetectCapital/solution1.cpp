#include <iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word)
    {
        bool all = false;       // all letters are lowercase
        bool foundL = false;    // whether find lowercase letter in the word (not the first one)
        bool foundU = false;    // whether find uppercase letter in the word (not the first one)

        for (int i=0; i<word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                if (i == 0)
                    all = true;
                else
                    foundL = true;
            }

            if (word[i] >= 'A' && word[i] <= 'Z' && i>0)
                foundU = true;

            if (all && foundU)
                return false;

            if (foundU && foundL)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solu;
    string str1 = "USA";
    cout << str1 << ": " << solu.detectCapitalUse(str1) << endl;
    string str2 = "FlaG";
    cout << str2 << ": " << solu.detectCapitalUse(str2) << endl;
    return 0;
}

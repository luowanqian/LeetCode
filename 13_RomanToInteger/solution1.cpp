#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int num = 0;
        int j;
        char ch;

        for (int i=0; i<s.size(); i++) {
            ch = s[i];
            j = i + 1;
            switch (ch) {
                case 'I':   // value 1
                    if (j < s.size() && (s[j] == 'V' || s[j] == 'X'))
                        num -= 1;
                    else
                        num += 1;
                    break;
                case 'V':   // value 5
                    num += 5;
                    break;
                case 'X':   // value 10
                    if (j < s.size() && (s[j] == 'L' || s[j] == 'C'))
                        num -= 10;
                    else
                        num += 10;
                    break;
                case 'L':   // value 50
                    num += 50;
                    break;
                case 'C':   // value 100
                    if (j < s.size() && (s[j] == 'D' || s[j] == 'M'))
                        num -= 100;
                    else
                        num += 100;
                    break;
                case 'D':   // value 500
                    num += 500;
                    break;
                case 'M':   // value 1000
                    num += 1000;
                    break;
            }
        }

        return num;
    }
};

int main()
{
    Solution solu;
    string str1 = "MCMXCIV";

    cout << str1 << ": " << solu.romanToInt(str1) << endl;

    return 0;
}
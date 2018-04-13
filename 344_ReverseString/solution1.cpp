#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s)
    {
        int i = 0, j = s.size() - 1;
        char tmp;

        while (i < j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;

            i++;
            j--;
        }

        return s;
    }
};

int main()
{
    Solution solu;
    string str1 = "hello";

    cout << str1 << " " << solu.reverseString(str1) << endl;

    return 0;
}
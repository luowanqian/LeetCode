#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s)
    {
        int start, end;
        char tmp;

        start = 0;
        end = s.size();
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                end = i - 1;

                // reverse word
                while (start < end) {
                    tmp = s[start];
                    s[start] = s[end];
                    s[end] = tmp;
                    start++;
                    end--;
                }

                while (i < s.size() && s[i] == ' ')
                    i++;
                start = i;
            }
        }

        // process last word
        end = s.size() - 1;
        while (start < end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }

        return s;
    }
};

int main()
{
    Solution solu;
    string str1 = "Let's take LeetCode contest";

    cout << str1 << endl;
    cout << solu.reverseWords(str1) << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;

        stack<char> brackets;
        char ch;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (brackets.empty())
                    return false;

                ch = brackets.top();
                if ((ch == '(' && s[i] != ')')
                    || (ch == '{' && s[i] != '}')
                    || (ch == '[' && s[i] != ']'))
                    return false;
                brackets.pop();
            }
        }
        if (!brackets.empty())
            return false;

        return true;
    }
};

int main()
{
    string str = "(a + b)";
    Solution solu;

    cout << solu.isValid(str) << endl;

    return 0;
}

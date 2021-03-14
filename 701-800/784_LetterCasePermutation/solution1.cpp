//
// Created by 罗万千 on 2021/3/14.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;

        if (S.length() == 0)
            return res;

        char* buffer = new char[S.length() + 1];
        sprintf(buffer, "%s", S.c_str());

        backtrack(buffer, 0, S.length(), res);

        delete [] buffer;

        return res;
    }

    void backtrack(char* str, int pos, int n, vector<string>& result) {
        if (pos == n) {
            result.push_back(string(str));
            return;
        }

        if (str[pos] <= '9' && str[pos] >= '0') {
            backtrack(str, pos + 1, n, result);
        } else {
            str[pos] = tolower(str[pos]);
            backtrack(str, pos+1, n, result);

            str[pos] = toupper(str[pos]);
            backtrack(str, pos+1, n, result);
        }
    }
};

int main()
{
    string s = "a1b2";
    Solution solu;
    vector<string> result = solu.letterCasePermutation(s);
    for (int i=0; i<result.size(); i++)
        cout << result[i] << endl;
    return 0;
}

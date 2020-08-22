/*
 * 2020-08-21
 */

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> maps = {"abc",
                               "def",
                               "ghi",
                               "jkl",
                               "mno",
                               "pqrs",
                               "tuv",
                               "wxyz"};
        vector<string> res;
        if (digits.size() == 0)
            return res;

        queue<string> q;
        int count;
        int index;

        index = digits[0] - '2';
        for (int i=0; i<maps[index].size(); i++) {
            q.push(maps[index].substr(i, 1));
        }
        for (int i=1; i<digits.size(); i++) {
            index = digits[i] - '2';
            count = q.size();
            while (count > 0) {
                string str = q.front();
                q.pop();
                for (int j=0; j<maps[index].size(); j++) {
                    q.push(str + maps[index].substr(j, 1));
                }
                count--;
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main()
{
    string digits = "23";
    Solution solu;
    vector<string> res = solu.letterCombinations(digits);
    for (int i=0; i<res.size(); i++)
        cout << res[i] << endl;

    return 0;
}
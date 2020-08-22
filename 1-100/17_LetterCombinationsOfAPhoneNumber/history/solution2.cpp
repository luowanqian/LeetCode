#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> m_maps;
    vector<string> m_res;
public:
    Solution() {
        m_maps = {"abc",
                  "def",
                  "ghi",
                  "jkl",
                  "mno",
                  "pqrs",
                  "tuv",
                  "wxyz"};
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return m_res;
        back_tracking("", digits);
        return m_res;
    }

    void back_tracking(string combination, string candidate) {
        if (candidate.size() == 0) {
            m_res.push_back(combination);
            return;
        }

        int digit = candidate[0] - '2';
        string letters = m_maps[digit];
        for (int i=0; i<letters.size(); i++) {
            back_tracking(combination + letters.substr(i, 1), candidate.substr(1));
        }
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


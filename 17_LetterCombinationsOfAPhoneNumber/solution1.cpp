#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int digit;
        int num_combs;
        string letters;
        string comb;
        vector<string> results;
        queue<string> combinations;
        vector<string> maps = {"abc", "def",
                               "ghi", "jkl",
                               "mno", "pqrs",
                               "tuv", "wxyz"};

        if (digits.size() == 0)
            return results;

        digit = digits[0] - '0';
        letters = maps[digit - 2];
        for (auto i=0; i<letters.size(); i++) {
            comb = letters[i];
            combinations.push(comb);
        }

        for (auto i=1; i<digits.size(); i++) {
            digit = digits[i] - '0';
            letters = maps[digit - 2];
            num_combs = combinations.size();
            for (auto j=0; j<num_combs; j++) {
                for (auto k=0; k<letters.size(); k++) {
                    comb = combinations.front();
                    comb += letters[k];
                    combinations.push(comb);
                }
                combinations.pop();
            }
        }

        while (!combinations.empty()) {
            results.push_back(combinations.front());
            combinations.pop();
        }

        return results;
    }
};

int main()
{
    string digits = "234";
    Solution solu;
    vector<string> combinations;

    combinations = solu.letterCombinations(digits);
    for (auto i=0; i<combinations.size(); i++)
        cout << combinations[i] << ", ";
    cout << endl;

    return 0;
}
/*
 * 2020-08-16
 * Time Limit Exceeded
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    void find_all_permutations(vector<string>& permutations, int start, string& str)
    {
        if (start >= str.size()) {
            permutations.push_back(str);
        } else {
            set<char> unique;
            for (int i=start; i<str.size(); i++) {
                if (unique.find(str[i]) != unique.end())
                    continue;
                unique.insert(str[i]);
                swap(str[i], str[start]);
                find_all_permutations(permutations, start+1, str);
                swap(str[i], str[start]);
            }
        }
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        set<int> unique_idx;
        vector<string> permuations;

        find_all_permutations(permuations, 0, p);
        for (int i=0; i<permuations.size(); i++) {
            size_t found = -1;
            while ((found = s.find(permuations[i], found+1)) != string::npos) {
                result.push_back(found);
            }
        }

        return result;
    }
};

int main()
{
    string s = "abab";
    string p = "ab";

    Solution solu;
    vector<int> index = solu.findAnagrams(s, p);
    for (int i=0; i<index.size(); i++) {
        cout << index[i] << " ";
    }
    cout << endl;

    return 0;
}
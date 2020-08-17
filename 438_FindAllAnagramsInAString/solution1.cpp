/*
 * 2020-08-17
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left, right;
        int match;
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        vector<int> res;

        for (int i=0; i<p.size(); i++)
            need[p[i]]++;
        left = right = 0;
        match = 0;

        while (right < s.size()) {
            char c1 = s[right];
            if (need.count(c1)) {
                window[c1]++;
                if (window[c1] == need[c1])
                    match++;
            }
            right++;

            while (match == need.size()) {
                if (right - left == p.size())
                    res.push_back(left);
                char c2 = s[left];
                if (need.count(c2)) {
                    window[c2]--;
                    if (window[c2] < need[c2])
                        match--;
                }
                left++;
            }
        }

        return res;
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

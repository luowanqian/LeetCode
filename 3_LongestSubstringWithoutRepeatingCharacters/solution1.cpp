/*
 * 2020-08-17
 */

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left, right;
        int res;
        unordered_map<char, int> window;

        res = 0;
        while (right < s.size()) {
            char c1 = s[right];
            window[c1]++;
            right++;

            while (window[c1] > 1) {
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            res = max(res, right - left);
        }

        return res;
    }
};

int main()
{
    string s = "pwwkew";
    Solution solu;
    cout << solu.lengthOfLongestSubstring(s) << endl;

    return 0;
}
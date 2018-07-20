#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> compute_prefix(string& pattern) {
        if (pattern.empty())
            return vector<int>();

        int len, pos;
        vector<int> prefix(pattern.size(), 0);

        len = 0;
        prefix[len] = 0;
        pos = 1;
        while (pos < pattern.size()) {
            if (pattern[pos] == pattern[len]) {
                len++;
                prefix[pos] = len;
                pos++;
            } else {
                if (len != 0) {
                    len = prefix[len-1];
                } else {
                    prefix[pos] = 0;
                    pos++;
                }
            }
        }

        return prefix;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int i, j;
        int text_len, pattern_len;
        vector<int> prefix;

        text_len = haystack.size();
        pattern_len = needle.size();

        // compute the length of longest prefix of pattern
        prefix = compute_prefix(needle);

        i = 0;  // index for text
        j = 0;  // index for pattern
        while (i < text_len) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == pattern_len) {
                return i - j;
            } else if (i < text_len && haystack[i] != needle[j]) {
                if (j != 0)
                    j = prefix[j-1];
                else
                    i = i + 1;
            }
        }

        return -1;
    }
};

int main()
{
    string haystack = "hello";
    string needle = "ll";
    Solution solu;

    cout << solu.strStr(haystack, needle) << endl;

    return 0;
}

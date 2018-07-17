#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return string();

        string common;
        string *shortest_str;
        char common_ch;
        int min_len;

        min_len = INT_MAX;
        for (auto it=strs.begin(); it!=strs.end(); ++it) {
            if (min_len > it->size()) {
                min_len = it->size();
                shortest_str = &(*it);
            }
        }

        for (int i=0; i<min_len; i++) {
            common_ch = strs[0][i];
            for (auto it=strs.begin(); it!=strs.end(); ++it)
                if (common_ch != (*it)[i])
                    return strs[0].substr(0, i);
        }

        return *shortest_str;
    }
};

int main() {
    //vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"aa", "a"};
    Solution solu;
    cout << solu.longestCommonPrefix(strs) << endl;

    return 0;
}

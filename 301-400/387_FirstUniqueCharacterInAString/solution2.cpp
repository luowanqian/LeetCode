#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int res = s.size();
        vector<int> idxes(26, -1), counts(26, 0);
        for (int i=0; i<s.size(); i++) {
            int num = s[i] - 'a';
            counts[num]++;
            idxes[num] = i;
        }

        for (int i=0; i<26; i++) {
            if (counts[i] == 1) {
                res = idxes[i] < res ? idxes[i] : res;
            }
        }

        return res == s.size() ? -1 : res;
    }
};

int main()
{
    string s = "loveleetcode";
    Solution solu;

    cout << solu.firstUniqChar(s) << endl;

    return 0;
}
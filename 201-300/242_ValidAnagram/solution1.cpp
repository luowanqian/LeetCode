#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        int match = 0;
        vector<int> sCount(26, 0), tCount(26, 0);

        for (auto& ch : t)
            tCount[ch - 'a']++;
        
        for (auto& ch : s) {
            int idx = ch - 'a';
            sCount[idx]++;
            if (sCount[idx] > tCount[idx])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solu;
    string s = "anagram";
    string t = "nagaram";
    cout << solu.isAnagram(s, t) << endl;;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> needs(26, 0), provides(26, 0);

        for (auto ch : magazine) {
            provides[ch - 'a']++;
        }
        for (auto ch : ransomNote) {
            int idx = ch - 'a';
            needs[idx]++;
            if (needs[idx] > provides[idx])
                return false;
        }
        
        return true;
    }
};

int main()
{
    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s.canConstruct(ransomNote, magazine) << endl;;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool delimter(char ch)
    {
        if (ch == ' ' || ch == '!' ||
            ch == '?' || ch == '\'' ||
            ch == ',' || ch == ';' || ch == '.')
            return true;
        else
            return false;
    }

    void lowercase(string& str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        unordered_set<string> banned_list;
        for (int i=0; i<banned.size(); i++)
            banned_list.insert(banned[i]);

        char ch;
        int times, max_times;
        string str, common_str;
        int start, end;
        unordered_map<string, int> word_counts;

        start = 0;
        max_times = 0;
        common_str = "";
        for (int i=0; i<paragraph.size(); i++) {
            if (delimter(paragraph[i])) {
                end = i;

                str = string(paragraph, start, end-start);
                lowercase(str);

                if (banned_list.find(str) == banned_list.end()) {
                    auto it = word_counts.find(str);
                    if (it == word_counts.end()) {
                        word_counts.insert(make_pair(str, 1));
                        times = 1;
                    } else {
                        it->second = it->second + 1;
                        times = it->second;
                    }
                    if (times > max_times) {
                        common_str = str;
                        max_times = times;
                    }
                }

                while (i<paragraph.size() && delimter(paragraph[i]))
                    i++;

                start = i;
            }
        }

        // the last word
        end = paragraph.size();
        if (start < end) {
            str = string(paragraph, start, end-start);
            lowercase(str);
            if (banned_list.find(str) == banned_list.end()) {
                auto it = word_counts.find(str);
                if (it == word_counts.end()) {
                    word_counts.insert(make_pair(str, 1));
                    times = 1;
                } else {
                    it->second = it->second + 1;
                    times = it->second;
                }
                if (times > max_times) {
                    common_str = str;
                    max_times = times;
                }
            }
        }

        return common_str;
    }
};

int main()
{
    Solution solu;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};

    cout << solu.mostCommonWord(paragraph, banned) << endl;

    return 0;
}
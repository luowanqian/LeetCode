/*
 * 每个字符串算一个hash值，如果是字母异位词，则hash值一样，这里很考验hash函数设计
 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
                              37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
                              79, 83, 89, 97, 101};
        unordered_map<double, unordered_map<int, int>> str_ht;

        for (string& str : strs) {
            double hash = 1;
            for (char& ch : str) {
                hash *= primes[ch - 'a'];
            }
            if (str_ht.count(hash) && str_ht[hash].count(str.size())) {
                int pos = str_ht[hash][str.size()];
                res[pos].push_back(str);
            } else {
                res.push_back({str});
                str_ht[hash][str.size()] = res.size() - 1;
            }
        }

        return res;
    }
};

int main()
{
    vector<string> strs = {"has","rod","tom","hum","him","yon","met","dye"};
    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> strs = {""};
    vector<vector<string>> res;
    Solution solu;

    res = solu.groupAnagrams(strs);
    for (auto& x : res) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
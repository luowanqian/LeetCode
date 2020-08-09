/*
 * My Solution
 * 2020-08-09
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> results;
        for (int i=0; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int max_end = end;
            for (int j=i+1; j<intervals.size(); j++) {
                int next_start = intervals[j][0];
                int next_end = intervals[j][1];
                if (next_start > max_end) {
                    i = j - 1;
                    break;
                }
                if (next_end > max_end)
                    max_end = next_end;
                i = j;
            }
            results.push_back({start, max_end});
        }

        return results;
    }
};

int main()
{
    vector<vector<int>> intervals = { {1, 3},
                                      {2, 6}};
    Solution solu;
    vector<vector<int>> merged = solu.merge(intervals);

    for (int i=0; i<merged.size(); i++) {
        cout << "[" << merged[i][0] << ", " << merged[i][1] << "]" << endl;
    }

    return 0;
}
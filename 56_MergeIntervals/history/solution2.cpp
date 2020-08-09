/*
 * Solution
 * 2020-08-09
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return vector<vector<int>>();

        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b) {
                      return a[0] < b[0];
        });
        vector<vector<int>> results;

        int start = intervals[0][0];
        int max_end = intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] > max_end) {
                results.push_back({start, max_end});
                start = intervals[i][0];
            }
            max_end = max(intervals[i][1], max_end);
        }
        results.push_back({start, max_end});

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

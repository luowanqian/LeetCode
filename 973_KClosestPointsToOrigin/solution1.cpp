/*
 * 2020-08-12
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        int dist;
        int x, y;
        for (int i=0; i<points.size(); i++) {
            x = points[i][0];
            y = points[i][1];
            dist = x*x + y*y;
            if (pq.size() < K) {
                pq.push(make_pair(dist, i));
            } else {
                if (pq.top().first > dist) {
                    pq.pop();
                    pq.push(make_pair(dist, i));
                }
            }
        }

        vector<vector<int>> results;
        while (!pq.empty()) {
            results.push_back(points[pq.top().second]);
            pq.pop();
        }

        return results;
    }
};

int main()
{
    vector<vector<int>> points = { {3, 3}, {5, -1}, {-2, 4} };
    int K = 2;
    Solution solu;
    vector<vector<int>> results = solu.kClosest(points, K);
    for (int i=0; i<results.size(); i++) {
        cout << results[i][0] << ", " << results[i][1] << endl;
    }
    return 0;
}
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0)
            return 0;
        else if (cost.size() == 1)
            return cost[0];
        else if (cost.size() == 2)
            return cost[0] > cost[1] ? cost[1] : cost[0];

        vector<int> min_cost(cost.size(), 0);
        int min = 0;
        int len = cost.size();

        min_cost[0] = cost[0];
        min_cost[1] = cost[1];

        for (int i=2; i<cost.size(); i++) {
            min = min_cost[i-1] + cost[i];
            if (min_cost[i-2] + cost[i] < min)
                min = min_cost[i-2] + cost[i];
            min_cost[i] = min;
        }

        min = min_cost[len - 1] > min_cost[len - 2] ?
              min_cost[len - 2] : min_cost[len - 1];

        return min;
    }
};

int main()
{
    Solution solu;

    vector<int> cost1 = {10, 15, 20};
    cout << solu.minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solu.minCostClimbingStairs(cost2) << endl;

    return 0;
}
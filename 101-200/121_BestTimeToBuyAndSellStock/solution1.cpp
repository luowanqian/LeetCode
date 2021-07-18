/*
 * 需要记录第i-1天之前股票最低值 min_prices[i-1]，这样第i天的利润可以计算为 max(0, prices[i] - min_prices[i-1])
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * 修改prices数组，避免申请空间，有点作弊味道
     */
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i=1; i<prices.size(); i++) {
            int profit = prices[i] - prices[i-1];
            if (profit > res)
                res = profit;
            prices[i] = min(prices[i], prices[i-1]);
        }

        return res;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> min_prices(prices.size(), 0);

        min_prices[0] = prices[0];
        for (int i=1; i<prices.size(); i++) {
            int profit = prices[i] - min_prices[i-1];
            if (profit > res)
                res = profit;
            min_prices[i] = min(prices[i], min_prices[i-1]);
        }

        return res;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    //vector<int> prices = {7,6,4,3,1};
    Solution solu;
    Solution2 solu2;
    cout << solu2.maxProfit(prices) << endl;
    cout << solu.maxProfit(prices) << endl;
    return 0;
}
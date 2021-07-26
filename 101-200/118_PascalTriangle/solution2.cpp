#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int>>();
        } else if (numRows == 1) {
            return {{1}};
        } else if (numRows == 2) {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> res = {{1}, {1, 1}};
        for (int i=2; i<numRows; i++) {
            vector<int> row = {1};
            for (int j=1; j<i; j++) {
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            row.push_back(1);
            res.push_back(row);
        }

        return res;
    }
};

int main()
{
    Solution solu;
    int numRows = 5;

    vector<vector<int>> res = solu.generate(numRows);

    for (auto& row : res) {
        for (auto& x : row)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
//
// Created by 罗万千 on 2021/3/14.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int max = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                backtrack(grid, i, j, 0, max);
            }
        }

        return max;
    }

    void backtrack(vector<vector<int>>& grid, int row, int col, int value, int& max) {
        if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
            if (value > max)
                max = value;
            return;
        }

        int currValue = grid[row][col];
        grid[row][col] = 0;
        backtrack(grid, row+1, col, currValue+value, max);
        backtrack(grid, row, col+1, currValue+value, max);
        backtrack(grid, row, col-1, currValue+value, max);
        backtrack(grid, row-1, col, currValue+value, max);
        grid[row][col] = currValue;
    }
};

int main()
{
    vector<vector<int>> grid = {
            {0, 6, 0},
            {5, 8, 7},
            {0, 9, 0}
    };
    Solution solu;
    cout << solu.getMaximumGold(grid);

    return 0;
}

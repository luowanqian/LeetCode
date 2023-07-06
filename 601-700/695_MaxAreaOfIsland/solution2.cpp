/*
 * History:
 *  2023.7.6 : first version
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, sum);
                }
                if (sum > res) {
                    res = sum;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &grid, int x, int y, int &sum)
    {
        sum += 1;
        grid[x][y] = -1;

        if ((x-1 >= 0) && grid[x-1][y] == 1) {
            dfs(grid, x-1, y, sum);
        }
        if ((x+1 < grid.size()) && grid[x+1][y] == 1) {
            dfs(grid, x+1, y, sum);
        }
        if ((y-1 >= 0) && grid[x][y-1] == 1) {
            dfs(grid, x, y-1, sum);
        }
        if ((y+1 < grid[0].size()) && grid[x][y+1] == 1) {
            dfs(grid, x, y+1, sum);
        }
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;

    return 0;
}
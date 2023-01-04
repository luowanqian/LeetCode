#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
private:
    queue<pair<int, int>> trace;
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int numRows = grid.size();
        int numCols = numRows > 0 ? grid[0].size() : 0;

        for (int i=0; i<numRows; i++) {
            for (int j=0; j<numCols; j++) {
                if (grid[i][j] != '0') {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        trace.push(make_pair(row, col));
        int numRows = grid.size();
        int numCols = numRows > 0 ? grid[0].size() : 0;
        grid[row][col] = '0';

        while (!trace.empty())
        {
            auto point = trace.front();
            int r = point.first;
            int c = point.second;
            trace.pop();
            if (r-1 >= 0 && grid[r-1][c] != '0') {
                trace.push(make_pair(r-1, c));
                grid[r-1][c] = '0';
            }
            if (r+1 < numRows && grid[r+1][c] != '0') {
                trace.push(make_pair(r+1, c));
                grid[r+1][c] = '0';
            }
            if (c-1 >= 0 && grid[r][c-1] != '0') {
                trace.push(make_pair(r, c-1));
                grid[r][c-1] = '0';
            }
            if (c+1 < numCols && grid[r][c+1] != '0') {
                trace.push(make_pair(r, c+1));
                grid[r][c+1] = '0';
            }
        }
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution solu;

    cout << solu.numIslands(grid) << endl;

    return 0;
}
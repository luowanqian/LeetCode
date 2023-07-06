/*
 * LeetCode 200. Number of Islands
 * History:
 *  2023.6.26 : first version, 并查集实现
 */

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int nrows = grid.size();
        int ncols = grid[0].size();
        int n = nrows * ncols;

        // initialization
        dsMap.resize(n, 0);
        for (int i = 0; i < n; i++) {
            dsMap[i] = i;
        }

        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                int idx = i * ncols + j;
                int idx2;
                if ((i-1) >= 0 && grid[i-1][j] == '1') {
                    idx2 = (i - 1) * ncols + j;
                    Merge(idx, idx2);
                }
                if ((j+1) < ncols && grid[i][j+1] == '1') {
                    idx2 = i * ncols + (j + 1);
                    Merge(idx, idx2);
                }
                if ((i+1) < nrows && grid[i+1][j] == '1') {
                    idx2 = (i + 1) * ncols + j;
                    Merge(idx, idx2);
                }
                if ((j-1) >=0 && grid[i][j-1] == '1') {
                    idx2 = i * ncols + (j - 1);
                    Merge(idx, idx2);
                }
            }
        }

        int res = 0;
        unordered_set<int> islands;
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                int idx = i * ncols + j;
                int x = Find(idx);
                if (islands.count(x) == 0) {
                    islands.insert(x);
                    res++;
                }
            }
        }

        return res;
    }

    int Find(int x)
    {
        return dsMap[x] == x ? x : Find(dsMap[x]);
    }

    void Merge(int x, int y)
    {
        dsMap[Find(x)] = Find(y);
    }

private:
    vector<int> dsMap;
};

int main()
{
    /*
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    */

    vector<vector<char>> grid = {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '0', '1'},
        {'1', '1', '1', '0', '1'}
    };

    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}
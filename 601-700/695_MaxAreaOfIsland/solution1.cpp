#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n_rows = grid.size();
        int n_cols = grid[0].size();
        stack<vector<int>> path;
        int max_area = 0;
        int area = 0;
        int pos_r, pos_c;

        for (int r=0; r<n_rows; r++) {
            for (int c=0; c<n_cols; c++) {
                if (grid[r][c] == 1) {
                    area = 0;
                    path.push({r, c});

                    while (!path.empty()) {
                        vector<int> &pos = path.top();
                        pos_r = pos[0];
                        pos_c = pos[1];
                        grid[pos_r][pos_c] = 0;

                        if ((pos_r-1) >= 0 && grid[pos_r-1][pos_c] == 1) {
                            path.push({pos_r - 1, pos_c});
                        } else if ((pos_c+1) < n_cols && grid[pos_r][pos_c+1] == 1) {
                            path.push({pos_r, pos_c + 1});
                        } else if ((pos_r+1) < n_rows && grid[pos_r+1][pos_c] == 1) {
                            path.push({pos_r + 1, pos_c});
                        } else if ((pos_c-1) >= 0 && grid[pos_r][pos_c-1] == 1) {
                            path.push({pos_r, pos_c - 1});
                        } else {
                            path.pop();
                            area++;
                        }
                    }

                    if (max_area < area)
                        max_area = area;
                }
            }
        }

        return max_area;
    }
};

int main()
{
    vector<vector<int>> grid =
            {{0,0,1,0,0,0,0,1,0,0,0,0,0},
             {0,0,0,0,0,0,0,1,1,1,0,0,0},
             {0,1,1,0,1,0,0,0,0,0,0,0,0},
             {0,1,0,0,1,1,0,0,1,0,1,0,0},
             {0,1,0,0,1,1,0,0,1,1,1,0,0},
             {0,0,0,0,0,0,0,0,0,0,1,0,0},
             {0,0,0,0,0,0,0,1,1,1,0,0,0},
             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            cout << grid[i][j] << ", ";
        }
        cout << endl;
    }

    Solution solu;
    int max_area = solu.maxAreaOfIsland(grid);
    cout << "Max area: " << max_area << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (!mat.size())
            return mat;
        if ((r*c) != (mat.size()*mat[0].size()))
            return mat;

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(r, vector<int>(c));

        int pos_r = 0, pos_c = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                res[pos_r][pos_c] = mat[i][j];
                pos_c++;
                if (pos_c >= c) {
                    pos_r++;
                    pos_c = 0;
                }
            }
        }

        return res;
    }
};

int main()
{
    //vector<vector<int>> nums = {{1, 2}, {3, 4}};
    //int r = 1;
    //int c = 4;
    vector<vector<int>> nums = {{1, 2, 3, 4}};
    int r = 2;
    int c = 2;
    Solution solu;

    vector<vector<int>> res = solu.matrixReshape(nums, r, c);
    for (auto& row : res) {
        for (auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
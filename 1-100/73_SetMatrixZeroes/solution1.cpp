#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> nzRows, nzCols;
        int nRows = matrix.size();
        int nCols = matrix.size()>0 ? matrix[0].size() : 0;

        for (int i=0; i<nRows; i++) {
            for (int j=0; j<nCols; j++) {
                if (matrix[i][j] == 0) {
                    nzRows.push_back(i);
                    nzCols.push_back(j);
                }
            }
        }

        int r, c;
        for (int k=0; k<nzRows.size(); k++) {
            r = nzRows[k];
            c = nzCols[k];
            for (int i=0; i<nRows; i++) {
                matrix[i][c] = 0;
            }
            for (int j=0; j<nCols; j++) {
                matrix[r][j] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution solu;

    solu.setZeroes(matrix);

    for (auto& row : matrix) {
        for (auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
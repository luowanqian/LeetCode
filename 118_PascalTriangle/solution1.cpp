#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};
        else if (numRows == 1)
            return {{1}};
        else if (numRows == 2)
            return {{1}, {1, 1}};

        vector<vector<int>> triangle;
        vector<int> line;

        triangle.push_back({1});
        triangle.push_back({1, 1});
        for (int i=2; i<numRows; i++) {
            line.clear();
            line.push_back(1);

            for (int j=0; j<triangle[i-1].size()-1; j++)
                line.push_back(triangle[i-1][j] + triangle[i-1][j+1]);

            line.push_back(1);
            triangle.push_back(line);
        }

        return triangle;
    }
};

int main()
{
    int num_rows = 3;
    Solution solu;

    vector<vector<int>> ret = solu.generate(num_rows);
    for (int i=0; i<ret.size(); i++) {
        for (int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

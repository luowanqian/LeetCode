#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row_sets(9);
        vector<unordered_set<char>> column_sets(9);
        vector<unordered_set<char>> block_sets(9);

        char ch;
        int block_id;
        for (auto i=0; i<9; i++) {
            for (auto j=0; j<9; j++) {
                ch = board[i][j];

                if (ch == '.')
                    continue;

                if (row_sets[i].find(ch) == row_sets[i].end())
                    row_sets[i].insert(ch);
                else
                    return false;

                if (column_sets[j].find(ch) == column_sets[j].end())
                    column_sets[j].insert(ch);
                else
                    return false;

                block_id = int(i / 3.0) * 3 + int(j / 3.0);
                if (block_sets[block_id].find(ch) == block_sets[block_id].end())
                    block_sets[block_id].insert(ch);
                else
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    for (auto i=0; i<board.size(); i++) {
        for (auto j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    Solution solu;
    cout << "Is valid: " << solu.isValidSudoku(board) << endl;

    return 0;
}

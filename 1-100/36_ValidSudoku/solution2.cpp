#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_status[board.size()];
        int col_status[board.size()];
        int cell_status[board.size()];
        int digit, cell, block_size, num_blocks;

        for (int i=0; i<board.size(); i++) {
            row_status[i] = 0;
            col_status[i] = 0;
            cell_status[i] = 0;
        }

        block_size = int(sqrt(board.size()));
        num_blocks = board.size() / block_size;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;

                digit = 1 << (board[i][j] - '0');
                cell = (i / block_size) * num_blocks + (j / block_size);
                if ((row_status[i] & digit) != 0)
                    return false;
                if ((col_status[j] & digit) != 0)
                    return false;
                if ((cell_status[cell] & digit) != 0)
                    return false;
                row_status[i] |= digit;
                col_status[j] |= digit;
                cell_status[cell] |= digit;
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

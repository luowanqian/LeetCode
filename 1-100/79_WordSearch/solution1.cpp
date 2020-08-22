/*
 * 2020-08-21
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (back_tracking(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }

    bool back_tracking(vector<vector<char>>& board, string word, int start, int row, int col) {
        if (start >= word.size())
            return true;
        char c = word[start];
        if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size())
            return false;
        // valid candidate
        if (board[row][col] == c) {
            // place candidate
            board[row][col] = '#';

            // given the candidate, explore further
            if (back_tracking(board, word, start+1, row-1, col)) return true;
            if (back_tracking(board, word, start+1, row, col-1)) return true;
            if (back_tracking(board, word, start+1, row+1, col)) return true;
            if (back_tracking(board, word, start+1, row, col+1)) return true;

            // remove candidate
            board[row][col] = c;
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "ABCCED";
//    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
//    string word = "bdca";

    Solution solu;
    cout << solu.exist(board, word);
    return 0;
}
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            unordered_set<char> col;

            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row.count(board[i][j])) {
                        return false;
                    }
                    row.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (col.count(board[j][i])) {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_set<char> grid;

                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char num = board[row + i][col + j];
                        if (num != '.') {
                            if (grid.count(num)) {
                                return false; 
                            }
                            grid.insert(num);
                        }
                    }
                }
            }
        }

        return true; 
    }
};
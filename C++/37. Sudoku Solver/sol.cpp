class Solution {
private:
    bool isValidNumber(vector<vector<char>>& board, int num, int row, int col) {
        // check row and column
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == '1' + num | board[row][i] == '1' + num) {
                return false;
            }
        }
        
        // check the block
        
        int blockID = (row / 3) * 3 + (col / 3);
        int blockRow = (blockID / 3) * 3;
        int blockCol = (blockID % 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[blockRow + i][blockCol + j] == '1' + num)
                    return false;
            }
        }
        
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board, int row, int col, vector<vector<char>> &result) {
        if (!result.empty())
            return;
        
        // reach the end of sudoku
        if (row == 9) {
            result = board;
            return;
        }
        
        if (board[row][col] != '.') {
            if (col != 8) {
                solveSudoku(board, row, col+1, result);
            }
            else {
                solveSudoku(board, row+1, 0, result);
            }
        }
        else {
            for (int i = 0; i < 9; i++) {
                if (isValidNumber(board, i, row, col)) {
                    board[row][col] = '1' + i;
                    if (col != 8) {
                        solveSudoku(board, row, col+1, result);
                    }
                    else {
                        solveSudoku(board, row+1, 0, result);
                    }
                    board[row][col] = '.';              // backtracking
                }
            }
        }
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> result;
        solveSudoku(board, 0, 0, result);
        board = result;
    }
};
class Solution {
private:
    void backtrackNQueens(int n, vector<vector<char>> &board, int row, int &count) {
        // iterate through columns at the current row
        for (int col = 0; col < n; ++col) {
            if (isNotAttacked(n, board, row, col)) {
                // place the queue
                board[row][col] = 'Q';
                if (row + 1 == n) {
                    // reach the bottom and found a solution
                    count++;
                }
                else {
                    // move on to the next row
                    backtrackNQueens(n, board, row + 1, count);
                }
                // backtracking
                board[row][col] = '.';
            }
        }
    }
    
    bool isNotAttacked(int n, vector<vector<char>> &board, int row, int col) {
        for (int i = 0; i < row; i++) {
            // check the column
            if (board[i][col] != '.')               
                return false;
            
            // check the diagnal
            if ((col - row + i >= 0 && board[i][col-row+i] != '.') || (col + row - i < n && board[i][col+row-i] != '.'))
                return false;
            
            // no need to check row in each iteraion, we just choose one column at once
        }
        return true;
    }
    
public:
    int totalNQueens(int n) {
        if (!n) return 1;               // well, edge case
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int count = 0;
        backtrackNQueens(n, board, 0, count);
        return count;
    }
};
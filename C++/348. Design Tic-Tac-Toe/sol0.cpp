class TicTacToe {
private:
    vector<vector<int>> board;
    int size;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int candidate = player;
        
        bool colWin = true;
        for (int i = 0; i < size; i++) {
            if (board[i][col] != player) {
                colWin = false;
                break;
            }
        }
        if (colWin) return player;
        
        bool rowWin = true;
        for (int j = 0; j < size; j++) {
            if (board[row][j] != player) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return player;
        
        bool diag = true;
        if (row == col) {
            for (int i = 0; i < size; i++) {
                if (board[i][i] != player) {
                    diag = false;
                    break;
                }
            }
        }
        else {
            diag = false;
        }
        if (diag) return player;
        
        bool backDiag = true;
        if (row + col == size - 1) {
            for (int i = 0; i < size; i++) {
                if (board[i][size-1-i] != player) {
                    backDiag = false;
                    break;
                }
            }
        }
        else {
            backDiag = false;
        }
        
        if (backDiag) return player;
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
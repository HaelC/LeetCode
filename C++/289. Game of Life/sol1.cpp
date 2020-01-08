class Solution {
private:
    bool isLive(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        return (board[i][j] == 1 || board[i][j] == -1);
    }
    
    int getLiveNeighbors(vector<vector<int>>& board, int i, int j) {
        int lives = 0;
        vector<pair<int, int>> neighbors{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (auto neighbor : neighbors) {
            if (isLive(board, i + neighbor.first, j + neighbor.second)) {
                lives++;
            }
        }
        return lives;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = getLiveNeighbors(board, i, j);
                if (!isLive(board, i, j) && liveNeighbors == 3) {
                    board[i][j] = 2;            // from dead to live
                }
                if (isLive(board, i, j) && (liveNeighbors > 3 || liveNeighbors < 2)) {
                    board[i][j] = -1;           // from live to dead
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] > 0 ? 1 : 0);
            }
        }
    }
};
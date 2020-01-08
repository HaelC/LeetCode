class Solution {
private:
    bool isLive(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        return board[i][j] == 1;
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
        vector<vector<int>> temp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = getLiveNeighbors(board, i, j);
                if (liveNeighbors == 3 || (liveNeighbors == 2 && isLive(board, i, j))) {
                    temp[i][j] = 1;
                }
            }
        }
        board = temp;
    }
};
class Solution {
private:
    bool exist(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (word[index] != board[i][j] || visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        index = index + 1;
        if (exist(board, word, index, i - 1, j, visited) 
            || exist(board, word, index, i, j - 1, visited) 
            || exist(board, word, index, i + 1, j, visited)
            || exist(board, word, index, i, j + 1, visited)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
        
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
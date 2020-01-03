class Solution {
private:
    bool exist(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] != word[index]) {
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '*';
        index = index + 1;
        bool result = (exist(board, word, index, i - 1, j) 
           || exist(board, word, index, i, j - 1)
           || exist(board, word, index, i + 1, j)
           || exist(board, word, index, i, j + 1));
        board[i][j] = c;
        return result;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (exist(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
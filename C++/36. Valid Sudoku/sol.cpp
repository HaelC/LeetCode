class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool column[9][9] = {false};
        bool sub_boxes[9][9] = {false};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (row[i][num] || column[j][num] || sub_boxes[k][num])
                        return false;
                    row[i][num] = true;
                    column[j][num] = true;
                    sub_boxes[k][num] = true;
                }
            }
        }
        return true;
    }
};
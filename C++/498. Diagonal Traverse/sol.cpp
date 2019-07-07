class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> diagonal;
        int direction = 1;
        if (matrix.empty()) return diagonal;        // in case the matrix is empty
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;

        while (i + j <= m + n - 2) {
            diagonal.push_back(matrix[i][j]);
            if (direction) {
                if (i == 0) {
                    direction = 0;
                    if (j < n - 1)
                        ++j;
                    else
                        ++i;
                }
                else if (j == n - 1) {
                    direction = 0;
                    ++i;
                }
                else {
                    --i;
                    ++j;
                }
            }
            else if (!direction) {
                if (j == 0) {
                    direction = 1;
                    if (i < m - 1)
                        ++i;
                    else
                        ++j;
                }
                else if (i == m - 1) {
                    direction = 1;
                    ++j;
                }
                else {
                    ++i;
                    --j;
                }
            }
        }
        return diagonal;
    }
};
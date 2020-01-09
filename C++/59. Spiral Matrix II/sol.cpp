class Solution {
private:
    bool nextPlace(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        if (i < 0 || j < 0 || i >= n || j >= n) {
            return false;
        }
        return matrix[i][j] == 0;
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int row = 0, col = 0;
        
        for (int i = 1; i <= n * n; i++) {
            matrix[row][col] = i;
            if (!nextPlace(matrix, row + directions[direction][0], col + directions[direction][1])) {
                direction = (direction + 1) % 4;
            }
            row += directions[direction][0];
            col += directions[direction][1];
        }
        
        return matrix;
    }
};
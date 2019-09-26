class Solution {
private:
    int rows, columns;
    
    bool searchMatrix(vector<vector<int>>& matrix, int row, int column, int target) {
        if (row >= rows || column >= columns)
            return false;
        
        if (matrix[row][column] == target)
            return true;
        
        for (int i = row + 1; i < rows; ++i) {
            if (matrix[i][column] == target)
                return true;
        }
        
        for (int j = column + 1; j < columns; ++j) {
            if (matrix[row][j] == target)
                return true;
        }
        
        return searchMatrix(matrix, row+1, column+1, target);
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        rows = matrix.size();
        columns = matrix.size() ? matrix[0].size() : 0;
        int r = 0, c = 0;
        return searchMatrix(matrix, r, c, target);
    }
};
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        set<pair<int, int>> candidate;
        for (int i = 0; i < m; i++) {
            int rowMin = matrix[i][0], index = 0;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    index = j;
                }
            }
            candidate.insert({i, index});
        }
        
        for (int j = 0; j < n; j++) {
            int colMax = matrix[0][j], index = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] > colMax) {
                    colMax = matrix[i][j];
                    index = i;
                }
            }
            if (candidate.count({index, j}) > 0) {
                result.push_back(matrix[index][j]);
            }
        }
        
        return result;
    }
};
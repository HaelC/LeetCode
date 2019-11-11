class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;
            int nextr = r + direction[di].first;
            int nextc = c + direction[di].second;
            if (nextr >= 0 && nextr < m && nextc >= 0 && nextc < n && !visited[nextr][nextc]) {
                r = nextr;
                c = nextc;
            }
            else {
                di = (di + 1) % 4;
                r += direction[di].first;
                c += direction[di].second;
            }
        }
        return result;
    }
};
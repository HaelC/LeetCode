class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size(), n = m ? M[0].size() : 0, result = 0;
        
        vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 2, vector<int>(4, 0)));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j]) {
                    dp[i + 1][j + 1][0] = dp[i + 1][j][0] + 1;
                    result = max(result, dp[i + 1][j + 1][0]);
                    dp[i + 1][j + 1][1] = dp[i][j + 1][1] + 1;
                    result = max(result, dp[i + 1][j + 1][1]);
                    dp[i + 1][j + 1][2] = dp[i][j][2] + 1;
                    result = max(result, dp[i + 1][j + 1][2]);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (M[i][j]) {
                    dp[i + 1][j + 1][3] = dp[i + 2][j][3] + 1;
                    result = max(result, dp[i + 1][j + 1][3]);
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        
        bool obstacled = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) {
                obstacled = true;
            }
            if (!obstacled) {
                dp[i][0] = 1;
            }
        }
        
        obstacled = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) {
                obstacled = true;
            }
            if (!obstacled) {
                dp[0][i] = 1;
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
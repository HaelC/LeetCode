class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (t[i] == s[j]) {
                    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j];
                }
                else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
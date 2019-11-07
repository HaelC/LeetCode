class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.length();
        }
        if (word2.empty()) {
            return word1.length();
        }
        
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int pre_row = dp[i - 1][j];
                int pre_col = dp[i][j - 1];
                int pre_diagonal = dp[i - 1][j - 1];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(min(pre_row + 1, pre_col + 1), pre_diagonal);
                }
                else {
                    dp[i][j] = min(min(pre_row + 1, pre_col + 1), pre_diagonal + 1);
                }
            }
        }
        return dp[m][n];
    }
};
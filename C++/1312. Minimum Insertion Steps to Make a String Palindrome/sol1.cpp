class Solution {
public:
    int minInsertions(string s) {
        int size = s.length();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for (int len = 2; len <= size; len++) {
            for (int i = 0; i < size - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[0][size - 1];
    }
};
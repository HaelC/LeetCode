class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int comb = 0;
            for (int j = 1; j <= i; j++) {
                comb += dp[j - 1] * dp[i - j];
            }
            dp[i] = comb;
        }
        return dp[n];
    }
};
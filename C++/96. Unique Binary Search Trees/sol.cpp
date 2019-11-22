class Solution {
public:
    int numTrees(int n) {
        if (!n) 
            return 1;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int available = 0;
            for (int j = 1; j <= i; j++) {
                available += dp[j - 1] * dp[i - j];
            }
            dp[i] = available;
        }
        return dp[n];
    }
};
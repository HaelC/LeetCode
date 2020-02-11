class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int currentPrice = prices[i];
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], dp[j]);
                if (prices[j] < currentPrice - fee) {
                    dp[i] = max(dp[i], dp[j] + currentPrice - fee - prices[j]);
                }   
            }
        }
        
        return dp[n - 1];
    }
};
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int maxInRange = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; k++) {
                maxInRange = max(maxInRange, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + maxInRange * k);
            }
        }
        return dp[n - 1];
    }
};
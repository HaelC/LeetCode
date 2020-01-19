class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        
        int sum = 0, result = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            dp[i + 1] = sum % K;
            for (int j = 0; j <= i; j++) {
                if (dp[j] == dp[i + 1] || abs(dp[j] - dp[i + 1]) == K) {
                    result++;
                }
            }
        }
        return result;
    }
};
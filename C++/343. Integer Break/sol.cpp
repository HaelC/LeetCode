class Solution {
public:
    int integerBreak(int n) {
        int result = 0;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int j = 2; j <= n; j++) {
            int temp = 0;
            for (int i = 1; i < j; i++) {
                temp = max(temp, max(i * dp[j - i], i * (j - i)));
            }
            dp[j] = temp;
            result = max(temp, result);
        }
        
        return result;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        int amount = dp[1];
        for (int i = 1; i < n; i++) {
            dp[i + 1] = nums[i] + dp[i - 1];
            dp[i + 1] = max(dp[i + 1], dp[i]);
        }
        
        return dp[n];
    }
};
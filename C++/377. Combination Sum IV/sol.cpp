class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int num : nums) {
                if (i + num <= target) {
                    dp[i + num] += dp[i];
                }
            }
        }
        
        return dp[target];
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (dp[i]) {
                for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                    dp[i + j] = true;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
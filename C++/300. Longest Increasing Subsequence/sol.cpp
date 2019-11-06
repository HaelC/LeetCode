class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int max = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (max < dp[j] + 1) {
                        max = dp[j] + 1;
                    }
                }
            }
            dp[i] = max;
        }
        int result = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};
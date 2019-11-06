class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        // construct the dp table
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = 1;
            }
        }
        
        // find the longest
        int result = 0;
        for (auto i : dp) {
            if (i > result) {
                result = i;
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> prev(n, 0);
        
        for (int i = 0; i < n; i++) {
            prev[i] = i;
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        int largestIndex = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[largestIndex]) {
                largestIndex = i;
            }
        }
        
        vector<int> result;
        while (true) {
            result.push_back(nums[largestIndex]);
            if (largestIndex == prev[largestIndex]) {
                break;
            }
            largestIndex = prev[largestIndex];
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
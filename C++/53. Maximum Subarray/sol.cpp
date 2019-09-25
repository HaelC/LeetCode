class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currentMaxSum = nums[0];
        for (int j = 1; j < nums.size(); ++j) {
            currentMaxSum = max(nums[j], currentMaxSum + nums[j]);
            maxSum = max(maxSum, currentMaxSum);
        }
        
        return maxSum;
    }
};
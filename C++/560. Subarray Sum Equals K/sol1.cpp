class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        int result = 0;
        for (int i = 0; i < n; i++) {
            preSum[i+1] += preSum[i] + nums[i];
            for (int j = 0; j <= i; j++) {
                if (preSum[i + 1] - preSum[j] == k) {
                    result++;
                }
            }
        }
        return result;
    }
};
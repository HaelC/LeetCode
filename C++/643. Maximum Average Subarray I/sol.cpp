class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxKSum = 0, currentKSum = 0;
        for (int i = 0; i < k; i++) {
            maxKSum += nums[i];
        }
        currentKSum = maxKSum;
        
        for (int i = 1; i <= nums.size() - k; i++) {
            currentKSum = currentKSum - nums[i - 1] + nums[i + k - 1];
            maxKSum = max(maxKSum, currentKSum);
        }
        
        return 1.0 * maxKSum / k;
    }
};
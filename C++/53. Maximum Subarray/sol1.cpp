class Solution {
private:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int leftPart = maxSubArray(nums, left, mid);
        int rightPart = maxSubArray(nums, mid + 1, right);
        int crossPart = calculatingCross(nums, mid, left, right);
        return max(max(leftPart, rightPart), crossPart);
    }
    
    int calculatingCross(vector<int>& nums, int mid, int left, int right) {
        int sum = 0, leftCross = 0, rightCross = 0;
        for (int i = mid - 1; i >= left; i--) {
            sum += nums[i];
            leftCross = max(leftCross, sum);
        }
        
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightCross = max(rightCross, sum);
        }
        return leftCross + rightCross + nums[mid];
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};
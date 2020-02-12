class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minWrongVal = INT_MAX, maxWrongVal = INT_MIN, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                minWrongVal = min(minWrongVal, nums[i]);
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                maxWrongVal = max(maxWrongVal, nums[i]);
            }
        }
        
        int left = 0, right = n - 1;
        while (left < n) {
            if (nums[left] > minWrongVal) {
                break;
            }
            left++;
        }
        while (right >= 0) {
            if (nums[right] < maxWrongVal) {
                break;
            }
            right--;
        }
        return left > right ? 0 : right - left + 1;
    }
};
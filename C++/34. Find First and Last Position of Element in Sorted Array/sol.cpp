class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(2, -1);
        
        // find the left boundry
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        if (left == nums.size() || nums[left] != target)
            return result;
        
        result[0] = left;
        
        // find the right boundry
        right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (nums[left] == target)
            result[1] = left;
        else
            result[1] = left - 1;
        return result;
    }
};
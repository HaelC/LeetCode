class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }
    
    int findLast(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        if (nums[right] == target) {
            return right;
        }
        else if (nums[left] == target) {
            return left;
        }
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);
        return result;
    }
};
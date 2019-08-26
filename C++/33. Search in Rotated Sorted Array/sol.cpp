class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid, index;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;            
        }
        
        int rotated = left;
        left = 0; right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            index = (rotated + mid) % nums.size();
            if (nums[index] == target)
                return index;
            else if (nums[index] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return -1;
    }
};
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int size = nums.size();
        int m = size / 2;
        if (target != nums[m]) {
            return false;
        }
        
        int begin = -1, end = - 1;
        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        begin = left;
        
        left = m, right = size - 1;
        while (left < right) {
            int mid = left + ceil(1.0 * (right - left) / 2);
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        end = right;
        
        return (end - begin + 1) > size / 2.0;
    }
};
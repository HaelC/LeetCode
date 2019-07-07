class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, current = 0, remaining;
        for (auto ele : nums) {
            total += ele;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            remaining = total - current - nums[i];
            if (remaining == current) {
                return i;
            }
            current += nums[i];
        }
        
        return -1;
    }
};
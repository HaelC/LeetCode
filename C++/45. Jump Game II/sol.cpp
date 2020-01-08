class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        
        int n = nums.size(), left = 0, right = 0, step = 0;
        while (right < n) {
            step++;
            int maxRight = right;
            for (int i = left; i <= right; i++) {
                if (i + nums[i] >= n - 1) {
                    return step;
                }
                maxRight = max(i + nums[i], maxRight);
            }
            left = right + 1;
            right = maxRight;
        }
        return step;
    }
};
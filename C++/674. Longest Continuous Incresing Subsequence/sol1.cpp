class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int prev = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            prev = nums[i] > nums[i-1] ? prev + 1 : 1;
            result = result > prev ? result : prev;
        }
        return result;
    }
};
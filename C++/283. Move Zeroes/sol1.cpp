class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for (int num : nums) {
            if (num) {
                nums[ptr++] = num;
            }
        }
        
        for (int i = ptr; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
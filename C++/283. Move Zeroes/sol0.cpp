class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> copy(nums.size(), 0);
        int ptr = 0;
        for (int num : nums) {
            if (num) {
                copy[ptr++] = num;
            }
        }
        nums = copy;
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for (int num : nums) {
            if (num == 0) {
                zero++;
            }
            else if (num == 1) {
                one++;
            }
            else {
                two++;
            }
        }
        for (int i = 0; i < zero + one + two; i++) {
            if (i < zero) {
                nums[i] = 0;
            }
            else if (i < zero + one) {
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }

    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        for (int num : nums) {
            if (num > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            else if (num < firstMax && num > secondMax) {
                thirdMax = secondMax;
                secondMax = num;
            }
            else if (num < secondMax && num > thirdMax) {
                thirdMax = num;
            }
        }
        return thirdMax == LONG_MIN ? firstMax : thirdMax;
    }
};
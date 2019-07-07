class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int tempMax = -1, index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > tempMax) {
                tempMax = nums[i];
                index = i;
            }
        }
        
        for (auto &ele : nums) {
            if (ele * 2 > tempMax && ele != tempMax)
                return -1;
        }
        return index;
    }
};
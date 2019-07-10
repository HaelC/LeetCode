class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, k=0;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
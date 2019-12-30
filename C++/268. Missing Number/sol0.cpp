class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> missed(n + 1, true);
        
        for (int num : nums) {
            missed[num] = false;
        }
        for (int i = 0; i <= n; i++) {
            if (missed[i]) {
                return i;
            }
        }
        return -1;
    }
};
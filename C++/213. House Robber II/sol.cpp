class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int n = nums.size();
        vector<int> robWithoutLast(n + 1, 0);
        vector<int> robWithoutFirst(n + 1, 0);
        
        robWithoutLast[1] = nums[0];
        robWithoutFirst[2] = nums[1];
        
        for (int i = 1; i < n; i++) {
            robWithoutLast[i + 1] = max(robWithoutLast[i], robWithoutLast[i - 1] + nums[i]);
        }
        for (int i = 2; i < n; i++) {
            robWithoutFirst[i + 1] = max(robWithoutFirst[i], robWithoutFirst[i - 1] + nums[i]);
        }
        return max(robWithoutLast[n - 1], robWithoutFirst[n]);
    }
};
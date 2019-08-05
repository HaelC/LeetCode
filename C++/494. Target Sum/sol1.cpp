class Solution {
private:
    void findWays(vector<int> &nums, int S, int current, int index, int &result) {
        if (index == nums.size()) {
            if (S == current)
                result++;
        }
        else {
            findWays(nums, S, current + nums[index], index + 1, result);
            findWays(nums, S, current - nums[index], index + 1, result);
        }
    }
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        findWays(nums, S, 0, 0, result);
        return result;
    }
};
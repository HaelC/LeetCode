class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int currentSum = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if (currentSum == k) {
                result = i + 1;
            }
            else if (hashmap.count(currentSum - k) > 0) {
                result = max(result, i - hashmap[currentSum - k]);
            }
            if (hashmap.count(currentSum) == 0) {
                hashmap[currentSum] = i;
            }
        }
        return result;
    }
};
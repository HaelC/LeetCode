class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, prefixSum = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            result += hashmap[prefixSum - k];
            hashmap[prefixSum]++;
        }
        return result;
    }
};
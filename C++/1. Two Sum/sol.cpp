class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.count(nums[i]) > 0) {
                result.push_back(hashmap[nums[i]]);
                result.push_back(i);
            }
            else {
                // keeps the complement (target-nums[i]) as the key
                // so that we just need to go through the vector once
                hashmap[target-nums[i]] = i;
            }
        }
        
        return result;
    }
};
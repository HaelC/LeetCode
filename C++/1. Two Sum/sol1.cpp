class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            hashmap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashmap.count(complement) > 0 && hashmap[complement] != i) {
                result.push_back(i);
                result.push_back(hashmap[complement]);
                break;
            }
        }
        
        return result;
    }
};
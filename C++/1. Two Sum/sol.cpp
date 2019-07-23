class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashtable.count(nums[i]) > 0) {
                vector<int> result{hashtable[nums[i]], i};
                return result;
            }
            else {
                hashtable[target - nums[i]] = i;
            }
        }
        vector<int> a;
        return a;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets; 
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            unordered_set<int> hashset;
            for (int j = i + 1; j < nums.size(); j++) {
                if (hashset.count(nums[j]) > 0) {
                    vector<int> candidate{nums[i], target - nums[j], nums[j]};
                    sort(candidate.begin(), candidate.end());
                    if (triplets.count(candidate) == 0) { 
                        result.push_back(candidate);
                        triplets.insert(candidate);
                    }
                }
                else {
                    hashset.insert(target - nums[j]);
                }
            }
        }
        return result;
    }
};
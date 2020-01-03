class Solution {
private:
    void addSubset(vector<vector<int>>& result, vector<int>& nums, vector<int> current, int index) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        } 
        addSubset(result, nums, current, index + 1);
        current.push_back(nums[index]);
        addSubset(result, nums, current, index + 1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        addSubset(result, nums, current, 0);
        return result;
    }
};
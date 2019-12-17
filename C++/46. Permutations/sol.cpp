class Solution {
private:
    void permute(vector<vector<int>>& result, vector<int>& nums, vector<int> current, unordered_set<int> visited) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(i) == 0) {
                current.push_back(nums[i]);
                visited.insert(i);
                permute(result, nums, current, visited);
                current.pop_back();
                visited.erase(i);
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(result, nums, vector<int>(), unordered_set<int>());
        return result;
    }
};
class Solution {
private:
    void backtracking(set<vector<int>>& unique, vector<int> current, vector<int>& nums, unordered_set<int> visited) {
        if (current.size() == nums.size()) {
            unique.insert(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                current.push_back(nums[i]);
                backtracking(unique, current, nums, visited);
                visited.erase(i);
                current.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> unique;
        unordered_set<int> visited;
        backtracking(unique, {}, nums, visited);
        vector<vector<int>> result(unique.begin(), unique.end());
        return result;
    }
};
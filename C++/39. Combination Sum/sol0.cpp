class Solution {
private:
    void combinationSum(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        combinationSum(candidates, target, 0, path, result);
        return result;
    }
};
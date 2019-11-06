class Solution {
private:
    void combinationHelper(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            combinationHelper(candidates, target - candidates[i], i + 1, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> result;
        combinationHelper(candidates, target, 0, path, result);
        return result;
    }
};
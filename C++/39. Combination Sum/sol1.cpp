class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>());
        dp[0].push_back(vector<int>());
        
        for (auto candidate : candidates) {
            for (int smallerTarget = 0; smallerTarget + candidate <= target; smallerTarget++) {
                vector<vector<int>> existedCombinations = dp[smallerTarget];
                for (vector<int>& existedCombination: existedCombinations) {
                    existedCombination.push_back(candidate);
                }
                int newCombination = smallerTarget + candidate;
                dp[newCombination].insert(dp[newCombination].end(), existedCombinations.begin(), existedCombinations.end());
            }
        }
        return dp[target];
    }
};
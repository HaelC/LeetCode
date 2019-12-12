class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> temp;
            temp.push_back(dp[0] + triangle[i][0]);
            for (int j = 1; j < i; j++) {
                temp.push_back(min(dp[j - 1], dp[j]) + triangle[i][j]);
            }
            temp.push_back(dp[i - 1] + triangle[i][i]);
            dp = temp;
        }
        
        int result = dp[0];
        for (int i : dp) {
            if (i < result) {
                result = i;
            }
        }
        return result;
    }
};
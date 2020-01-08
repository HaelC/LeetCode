class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minLast = 20000;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        minLast = min(minLast, arr[i - 1][k]);
                    }
                }
                arr[i][j] += minLast;
            }
        }
        
        int minPath = 20000;
        for (int i = 0; i < n; i++) {
            minPath = min(minPath, arr[n - 1][i]);
        }
        
        return minPath;
    }
};
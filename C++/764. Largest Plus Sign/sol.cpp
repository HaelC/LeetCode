class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        int result = 0;
        for (auto mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) {
                    count++;
                    grid[i][j] = count;
                }
                else {
                    count = 0;
                }
            }
            
            count = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (grid[i][j]) {
                    count++;
                    grid[i][j] = min(count, grid[i][j]);
                }
                else {
                    count = 0;
                }
            }
        }
        
        for (int j = 0; j < N; j++) {
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (grid[i][j]) {
                    count++;
                    grid[i][j] = min(count, grid[i][j]);
                }
                else {
                    count = 0;
                }
            }
            
            count = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (grid[i][j]) {
                    count++;
                    grid[i][j] = min(count, grid[i][j]);
                    result = max(result, grid[i][j]);
                }
                else {
                    count = 0;
                }
            }
        }
        return result;
    }
};
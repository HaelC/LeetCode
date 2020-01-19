class Solution {
private:
    int rot(vector<vector<int>>& grid, queue<pair<int, int>>& bfs, int i, int j) {
        int adjacent = 0;
        if (i > 0 && grid[i-1][j] == 1) {
            grid[i - 1][j] = 2;
            bfs.push({i - 1, j});
            adjacent++;
        }
        if (j > 0 && grid[i][j - 1] == 1) {
            grid[i][j - 1] = 2;
            bfs.push({i, j - 1});
            adjacent++;
        }
        if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
            grid[i + 1][j] = 2;
            bfs.push({i + 1, j});
            adjacent++;
        }
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
            grid[i][j+1] = 2;
            bfs.push({i, j + 1});
            adjacent++;
        }
        return adjacent;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rottedNumber = 0, orangeNumber = 0;
        queue<pair<int, int>> bfs;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    orangeNumber++;
                }
                else if (grid[i][j] == 2) {
                    orangeNumber++;
                    rottedNumber++;
                    bfs.push({i, j});
                }
            }
        }
        
        if (rottedNumber == orangeNumber) {
            return 0;
        }
        
        int minute = 0;
        while (!bfs.empty()) {
            int size = bfs.size();
            minute++;
            for (int i = 0; i < size; i++) {
                auto p = bfs.front();
                bfs.pop();
                rottedNumber += rot(grid, bfs, p.first, p.second);
                if (rottedNumber >= orangeNumber) {
                    return minute;
                }
            }
        }
        
        return -1;
    }
};
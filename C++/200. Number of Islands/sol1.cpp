class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int islands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> adjacent;
                    adjacent.push({i, j});
                    while (!adjacent.empty()) {
                        pair<int, int> p = adjacent.front();
                        adjacent.pop();
                        int r = p.first, c = p.second;
                        if ((r - 1 >= 0) && grid[r-1][c] == '1') {
                            grid[r-1][c] = '0';
                            adjacent.push({r-1, c});
                        }
                        if ((c - 1 >= 0) && grid[r][c-1] == '1') {
                            grid[r][c-1] = '0';
                            adjacent.push({r, c-1});
                        }
                        if ((r + 1 < m) && grid[r+1][c] == '1') {
                            grid[r+1][c] = '0';
                            adjacent.push({r+1, c});
                        }
                        if ((c + 1 < n) && grid[r][c+1] == '1') {
                            grid[r][c+1] = '0';
                            adjacent.push({r, c+1});
                        }
                    }
                } 
            }
        }
        return islands;
    }
};
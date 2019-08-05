class Solution {
private:
    int m, n;
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, pair<int, int> coord) {
        int i = coord.first;
        int j = coord.second;
        visited[i][j] = true;
        if (j + 1 < n && grid[i][j+1] == '1' && !visited[i][j+1])
            dfs(grid, visited, {i, j+1});
        if (i + 1 < m && grid[i+1][j] == '1' && !visited[i+1][j])
            dfs(grid, visited, {i+1, j});
        if (j - 1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1])
            dfs(grid, visited, {i, j-1});
        if (i - 1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j])
            dfs(grid, visited, {i-1, j});
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        m = grid.size();
        n = m ? grid[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool> (n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++island;
                    dfs(grid, visited, {i, j});
                }
            }
        }
        return island;
    }
};
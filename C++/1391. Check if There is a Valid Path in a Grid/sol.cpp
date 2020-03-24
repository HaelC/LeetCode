class Solution {
private:
    bool invalidPos(pair<int, int> pos, int m, int n) {
        return pos.first < 0 || pos.second < 0 || pos.first >= m || pos.second >= n;
    }
    
    bool validateAndMove(vector<vector<int>>& grid, pair<int, int> pos, pair<int, int> dir) {
        int m = grid.size(), n = grid[0].size();
        int x = pos.first, y = pos.second;
        if (invalidPos(pos, m, n) || (x == 0 && y == 0)) {
            return false;
        }
        
        int street = grid[x][y];
        switch(street) {
            case 1:
                if (dir.first != 0) {
                    return false;
                }
                break;
            case 2:
                if (dir.second != 0) {
                    return false;
                }
                break;
            case 3:
                if (dir.second == 1) {
                    dir = {1, 0};
                }
                else if (dir.first == -1) {
                    dir = {0, -1};
                }
                else {
                    return false;
                }
                break;
            case 4:
                if (dir.second == -1) {
                    dir = {1, 0};
                }
                else if (dir.first == -1) {
                    dir = {0, 1};
                }
                else {
                    return false;
                }
                break;
            case 5:
                if (dir.second == 1) {
                    dir = {-1, 0};
                }
                else if (dir.first == 1) {
                    dir = {0, -1};
                }
                else {
                    return false;
                }
                break;
            case 6:
                if (dir.second == -1) {
                    dir = {-1, 0};
                }
                else if (dir.first == 1) {
                    dir = {0, 1};
                }
                else {
                    return false;
                }
                break;
            default:
                return false;
        }
        
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        
        pos.first += dir.first;
        pos.second += dir.second;
        return validateAndMove(grid, pos, dir);
    }
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int init = grid[0][0];
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) {
            return true;
        }
        
        switch (init) {
            case 1:
                return validateAndMove(grid, {0, 1}, {0, 1});
            case 2:
                return validateAndMove(grid, {1, 0}, {1, 0});
            case 3:
                return validateAndMove(grid, {1, 0}, {1, 0});
            case 4:
                return validateAndMove(grid, {0, 1}, {0, 1}) || validateAndMove(grid, {1, 0}, {1, 0});
            case 5:
                return false;
            case 6:
                return validateAndMove(grid, {0, 1}, {0, 1});
            default:
                return false;
        }
    }
};
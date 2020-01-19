class Solution {
private:
    void adjacent(vector<vector<int>>& rooms, queue<pair<int, int>>& bfs, int i, int j, int step) {
        if (i > 0 && rooms[i - 1][j] == INT_MAX) {
            rooms[i - 1][j] = step;
            bfs.push({i - 1, j});
        }
        if (j > 0 && rooms[i][j - 1] == INT_MAX) {
            rooms[i][j - 1] = step;
            bfs.push({i, j - 1});
        }
        if (i < rooms.size() - 1 && rooms[i + 1][j] == INT_MAX) {
            rooms[i + 1][j] = step;
            bfs.push({i + 1, j});
        }
        if (j < rooms[0].size() - 1 && rooms[i][j + 1] == INT_MAX) {
            rooms[i][j + 1] = step;
            bfs.push({i, j + 1});
        }
    }
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> bfs;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (!rooms[i][j]) {
                    bfs.push({i, j});
                }
            }
        }
        
        int step = 0;
        while (!bfs.empty()) {
            int size = bfs.size();
            step++;
            for (int i = 0; i < size; i++) {
                auto p = bfs.front();
                bfs.pop();
                adjacent(rooms, bfs, p.first, p.second, step);
            }
        }
    }
};
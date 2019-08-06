class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, unordered_set<int> &keys, int current) {
        visited[current] = true;
        for (auto key : rooms[current])
            keys.insert(key);
        for (auto key : keys)
            if (!visited[key])
                dfs(rooms, visited, keys, key);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numRoom = rooms.size();
        vector<bool> visited(numRoom);
        unordered_set<int> keys;
        dfs(rooms, visited, keys, 0);
        
        for (auto v : visited)
            if (!v) return false;
        return true;
    }
};
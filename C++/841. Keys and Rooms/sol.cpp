class Solution {
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            visited.insert(room);
            for (auto key : rooms[room]) {
                if (visited.find(key) == visited.end())
                    q.push(key);
            }
        }
        return visited.size() == rooms.size();
    }
};
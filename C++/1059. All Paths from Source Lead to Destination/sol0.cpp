class Solution {
private:
    #define WHITE 0
    #define GRAY 1
    #define BLACK 2

    bool dfs(vector<vector<int>>& graph, int src, int dest, vector<int>& status) {
        if (graph[src].empty()) {
            return src == dest;
        }
        
        status[src] = GRAY;
        for (auto next : graph[src]) {
            if (status[next] == GRAY) {
                return false;
            }
            else if (status[next] == WHITE) {
                if (!dfs(graph, next, dest, status)) {
                    return false;
                }
            }
        }
        status[src] = BLACK;
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> status(n, WHITE);
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs(graph, source, destination, status);
    }
};
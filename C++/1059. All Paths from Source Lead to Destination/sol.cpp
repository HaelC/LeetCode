class Solution {
private:
    void buildGraph(vector<vector<int>>& edges, vector<vector<int>>& graph) {
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
    }
    
    bool dfs(vector<vector<int>>& graph, int source, int destination, vector<bool> visited) {
        if (source == destination) {
            return graph[source].empty();
        }
        
        if (graph[source].empty()) {
            return false;
        }
        
        for (auto& next : graph[source]) {
            if (visited[next]) {
                return false;
            }
            visited[next] = true;
            if (!dfs(graph, next, destination, visited)) {
                return false;
            }
            visited[next] = false;
        }
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        buildGraph(edges, graph);
        return dfs(graph, source, destination, visited);
    }
};
class Solution {
private:
    void buildGraph(vector<vector<string>>& equations, vector<double>& values, unordered_map<string, unordered_map<string, double>>& graph) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string divisor = equations[i][0];
            string dividend = equations[i][1];
            double value = values[i];
            graph[divisor].insert({dividend, value});
            graph[dividend].insert({divisor, 1 / value});
        }
        
        for (auto p : graph) {
            graph[p.first].insert({p.first, 1});
        }
    }
    
    double bfs(unordered_map<string, unordered_map<string, double>>& graph, string divisor, string dividend) {
        if (graph.count(divisor) && graph[divisor].count(dividend)) {
            return graph[divisor][dividend];
        }
        if (!graph.count(divisor) || !graph.count(dividend)) {
            return -1.0;
        }
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        q.push({divisor, 1});
        visited.insert(divisor);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string temp = q.front().first;
                double val = q.front().second;
                q.pop();
                if (temp == dividend) {
                    return val;
                }
                for (auto edge : graph[temp]) {
                    if (!visited.count(edge.first)) {
                        q.push({edge.first, val * edge.second});
                        visited.insert(edge.first);
                    }
                }
            } 
        }
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> result;
        buildGraph(equations, values, graph);
        
        for (auto query : queries) {
            string divisor = query[0];
            string dividend = query[1];
            result.push_back(bfs(graph, divisor, dividend));
        }
        
        return result;
    }
};
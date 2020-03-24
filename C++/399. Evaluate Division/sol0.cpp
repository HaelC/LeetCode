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
    
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string> visited, string divisor, string dividend) {
        if (graph.count(divisor) && graph[divisor].count(dividend)) {
            return graph[divisor][dividend];
        }
        if (!graph.count(divisor) || !graph.count(dividend)) {
            return 0;
        }
        for (auto p : graph[divisor]) {
            if (visited.count(p.first) == 0) {
                visited.insert(p.first);
                double temp = dfs(graph, visited, p.first, dividend);
                if (temp) {
                    return p.second * temp;
                }
            } 
        }
        return 0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> result;
        buildGraph(equations, values, graph);
        
        for (auto query : queries) {
            string divisor = query[0];
            string dividend = query[1];
            unordered_set<string> visited;
            double temp = dfs(graph, visited, divisor, dividend);
            if (temp) {
                result.push_back(temp);
            }
            else {
                result.push_back(-1.0);
            }
        }
        
        return result;
    }
};
class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    
    void buildGraph(int n, vector<vector<int>>& flights) {
        graph = vector<vector<pair<int, int>>>(n);
        for (auto flight : flights) {
            int src = flight[0], dst = flight[1], price = flight[2];
            graph[src].push_back({dst, price});
        }
    }
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) {
            return 0;
        }
        buildGraph(n, flights);
        int result = INT_MAX;
        
        queue<pair<int, int>> bfs;
        
        int step = 0;
        bfs.push({src, 0});
        while (!bfs.empty() && step <= K) {
            step++;
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                auto temp = bfs.front();
                cout << temp.first << endl;
                bfs.pop();
                // if (temp.first == dst) {
                //     result = min(result, temp.second);
                // }
                for (auto e : graph[temp.first]) {
                    if (temp.second + e.second < result) {
                        bfs.push({e.first, temp.second + e.second});
                    }
                    if (e.first == dst) {
                        result = min(result, temp.second + e.second);
                    }
                }
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
class myCompare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<unordered_map<int, int>> graph(N + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pq;
        unordered_map<int, int> dist;
        int result = 0;
        
        for (auto edge : times) {
            graph[edge[0]][edge[1]] = edge[2];
        }
        
        pq.push({K, 0});
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int u = p.first, d = p.second;
            if (dist.count(u) > 0) {
                continue;
            }
            dist[u] = d;
            result = max(result, d);
            for (auto edge : graph[u]) {
                if (dist.count(edge.first) == 0) {
                    pq.push({edge.first, edge.second + d});
                }
            }
        }
        
        if (dist.size() != N) {
            return -1;
        }
        return result;
    }
};
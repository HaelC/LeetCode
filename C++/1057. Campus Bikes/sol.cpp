bool distSort(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    return p1.first < p2.first || p1.first == p2.first && p1.second.first < p2.second.first ||
        p1.first == p2.first && p1.second.first == p2.second.first && p1.second.second < p2.second.second;
}

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        vector<pair<int, pair<int, int>>> dists;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dists.push_back({dist, {i, j}});
            }
        }
        
        sort(dists.begin(), dists.end(), distSort);
        
        vector<int> result(m, -1);
        vector<bool> bikeAvailable(n, true);
        
        for (auto dist : dists) {
            int workerIndex = dist.second.first, bikeIndex = dist.second.second;
            if (result[workerIndex] == -1 && bikeAvailable[bikeIndex]) {
                result[workerIndex] = bikeIndex;
                bikeAvailable[bikeIndex] = false;
            }
        }
        
        return result;
    }
};
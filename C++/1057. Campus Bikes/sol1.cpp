class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        vector<vector<pair<int, int>>> dists(2001);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dists[dist].push_back({i, j});
            }
        }
        
        vector<int> result(m, -1);
        vector<bool> bikeAvailable(n, true);
        
        for (int i = 0; i <= 2000; i++) {
            for (int j = 0; j < dists[i].size(); j++) {
                int workerIndex = dists[i][j].first, bikeIndex = dists[i][j].second;
                if (result[workerIndex] == -1 && bikeAvailable[bikeIndex]) {
                    result[workerIndex] = bikeIndex;
                    bikeAvailable[bikeIndex] = false;
                }
            }
        }
        
        return result;
    }
};
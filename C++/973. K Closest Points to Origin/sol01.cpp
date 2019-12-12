class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dists;
        for (int i = 0; i < points.size(); i++) {
            dists.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        for (int i = 0; i < K; i++) {
            int index = dists.top().second;
            result.push_back(vector<int>{points[index][0], points[index][1]});
            dists.pop();
        }
        return result;
    }
};
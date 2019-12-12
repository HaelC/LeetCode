class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        vector<pair<int, int>> dists;
        for (int i = 0; i < points.size(); i++) {
            dists.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        sort(dists.begin(), dists.end());
        for (int i = 0; i < K; i++) {
            int index = dists[i].second;
            result.push_back(vector<int>{points[index][0], points[index][1]});
        }
        return result;
    }
};
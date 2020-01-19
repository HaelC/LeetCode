class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int dist = 0, minVal = arrays[0][0], maxVal = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            dist = max(dist, max(abs(arrays[i][0] - maxVal), abs(arrays[i].back() - minVal)));
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }
        return dist;
    }
};
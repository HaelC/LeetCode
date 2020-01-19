bool compareSecond(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), compareSecond);
        int lastEnd = points[0][1], arrows = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastEnd) {
                lastEnd = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};
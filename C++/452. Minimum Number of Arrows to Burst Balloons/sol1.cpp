bool myCompare(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 0;
        sort(points.begin(), points.end(), myCompare);
        int i = 0, size = points.size();
        while (i < size) {
            int arrow = points[i][1];
            arrows++;
            while (i < size && points[i][0] <= arrow && points[i][1] >= arrow) {
                i++;
            }
        }
        return arrows;
    }
};
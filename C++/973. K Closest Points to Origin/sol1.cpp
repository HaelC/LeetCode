class Solution {
public:
    typedef pair<vector<int>, int> point_dist;
    
    class my_compare {
    public:
        bool operator()(point_dist pd1, point_dist pd2) {
            return pd1.second > pd2.second;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<point_dist, vector<point_dist>, my_compare> pq;
        for (auto p : points) {
            pq.push({p, p[0] * p[0] + p[1] * p[1]});
        }
        vector<vector<int>> result;
        for (int i = 0; i < K; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
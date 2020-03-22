bool compareEfficiency(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second || (p1.second == p2.second && p1.first >= p2.first);
}
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        long result = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            v.push_back({speed[i], efficiency[i]});
        }
        sort(v.begin(), v.end(), compareEfficiency);
        for (int i = 0; i < k; i++) {
            sum += v[i].first;
            result = max(result, sum * v[i].second);
            pq.push(v[i].first);
        }
        
        for (int i = k; i < n; i++) {
            if (v[i].first > pq.top()) {
                sum = sum - pq.top() + v[i].first;
                pq.pop();
                pq.push(v[i].first);
                result = max(result, sum * v[i].second);
            }
        }
        
        return result % (1000000007);
    }
};
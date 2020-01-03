class pairCompare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> pq;
        vector<int> result;
        for (auto p : frequencies) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};
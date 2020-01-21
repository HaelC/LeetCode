class myCompare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> tapRanges;
        for (int i = 0; i < ranges.size(); i++) {
            tapRanges.push_back({i - ranges[i], i + ranges[i]});
        }
        
        vector<pair<int, int>> chosenTaps;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pq;
        
        for (auto p : tapRanges) {
            pq.push(p);
        }
        
        int lastRange = 0, result = 0;
        while (lastRange < n) {
            int temp = lastRange;
            result++;
            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                if (p.first <= lastRange) {
                    temp = max(temp, p.second);
                }
            }
            if (temp == lastRange) {
                return -1;
            }
            lastRange = temp;
            for (auto p : tapRanges) {
                if (p.second > lastRange) {
                    pq.push(p);
                }
            }
            if (lastRange >= n) {
                return result;
            }
            if (pq.empty()) {
                return -1;
            }
        }
        return result;
    }
};
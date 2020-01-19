class myCompare {
public:
    bool operator()(pair<char, int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, myCompare> pq;
        for (auto p : count) {
            pq.push(p);
        }
        string result = "";
        while (!pq.empty()) {
            char c = pq.top().first;
            int cnt = pq.top().second;
            pq.pop();
            for (int i = 0; i < cnt; i++) {
                result += c;
            }
        }
        return result;
    }
};
bool compareStart(vector<int>&t1, vector<int>& t2) {
    return t1[0] < t2[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareStart);
        priority_queue<int, vector<int>, greater<int>> pq;
        int rooms = 0;
        for (auto v : intervals) {
            if (!pq.empty() && v[0] >= pq.top()) {
                pq.pop();
            }
            pq.push(v[1]);
            rooms = pq.size() > rooms ? pq.size() : rooms;
        }
        return rooms;
    }
};
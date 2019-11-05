bool compareStartTime(vector<int>& t1, vector<int>& t2) {
    return t1[0] < t2[0];
}

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareStartTime);    
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }

        return true;
    }
};
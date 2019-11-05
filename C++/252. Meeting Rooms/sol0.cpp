class Solution {
private:
    // t1 and t2: two time intervals
    bool isOverlapped(vector<int>& t1, vector<int>& t2) {
        // t1[0]: start time, t1[1]: end time
        
        return t1[1] > t2[0] && t1[0] < t2[1];
    }
    
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) 
            return true;
        for (int i = 0; i < intervals.size() - 1; i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (isOverlapped(intervals[i], intervals[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
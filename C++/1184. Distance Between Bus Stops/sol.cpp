class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int totalDistance = 0;
        for (int dist : distance) {
            totalDistance += dist;
        }
        
        if (start > destination) {
            int temp = start;
            start = destination;
            destination = temp;
        }
        
        int dist = 0;
        for (int i = start; i < destination; i++) {
            dist += distance[i];
        }
        
        return min(dist, totalDistance - dist);
    }
};
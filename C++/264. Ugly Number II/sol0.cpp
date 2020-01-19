class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> visited;
        heap.push(1);
        for (int i = 1; i < n; i++) {
            long top = heap.top();
            heap.pop();
            if (visited.count(top * 2) == 0) {
                heap.push(top * 2);
                visited.insert(top * 2);
            }
            if (visited.count(top * 3) == 0) {
                heap.push(top * 3);
                visited.insert(top * 3);
            }
            if (visited.count(top * 5) == 0) {
                heap.push(top * 5);
                visited.insert(top * 5);
            }
        }
        return heap.top();
    }
};
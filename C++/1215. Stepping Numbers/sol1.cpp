class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        queue<long> bfs;
        vector<int> result;
        if (low == 0) {
            result.push_back(0);
        }
        
        for (int i = 1; i <= 9 && i <= high; i++) {
            bfs.push(i);
        }
        while (!bfs.empty()) {
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                long element = bfs.front();
                bfs.pop();
                if (element >= low) {
                    result.push_back(element);
                }
                int lastDigit = element % 10;
                if (lastDigit != 0 && element * 10 + lastDigit - 1 <= high) {
                    bfs.push(element * 10 + lastDigit - 1);
                }
                if (lastDigit != 9 && element * 10 + lastDigit + 1 <= high) {
                    bfs.push(element * 10 + lastDigit + 1);
                }
            }
        }
        
        return result;
    }
};
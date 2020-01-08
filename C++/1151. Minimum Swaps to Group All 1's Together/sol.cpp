class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (int num : data) {
            ones += num;
        }
        
        int left = 0, right = ones - 1, current = 0;
        for (int i = left; i <= right; i++) {
            current += data[i];
        }
        int minimum = ones - current;
        
        while (right < data.size() - 1) {
            current = current - data[left++] + data[++right];
            minimum = min(minimum, ones - current);
        }
        
        return minimum;
    }
};
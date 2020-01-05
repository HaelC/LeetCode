class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxElement = 0;
        for (int num : nums) {
            maxElement = max(maxElement, num);
        }
        
        int left = 1, right = maxElement;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int dividedSum = 0;
            for (int num : nums) {
                dividedSum += ceil(1.0 * num / mid);
            }
            if (dividedSum > threshold) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
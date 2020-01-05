class Solution {
private:
    int getMutatedSum(vector<int>& arr, int value) {
        int mutatedSum = 0;
        for (int num: arr) {
            if (num > value) {
                mutatedSum += value;
            }
            else {
                mutatedSum += num;
            }
        }
        return mutatedSum;
    }
    
public:
    int findBestValue(vector<int>& arr, int target) {
        int maxElement = 0, originalSum = 0;
        for (int num : arr) {
            maxElement = max(maxElement, num);
            originalSum += num;
        }
        
        if (target >= originalSum) {
            return maxElement;
        }
        
        int minDiff = target, result = 0;
        int left = 1, right = maxElement;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mutatedSum = getMutatedSum(arr, mid);
            int diff = abs(mutatedSum - target);
            if (diff < minDiff) {
                minDiff = diff;
                result = mid;
            }
            else if (diff == minDiff) {
                result = min(mid, result);
            }
            if (mutatedSum < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};
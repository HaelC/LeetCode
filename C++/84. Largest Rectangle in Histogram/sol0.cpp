class Solution {
private:
    int divideAndConquer(vector<int>& heights, int begin, int end) {
        if (begin > end) {
            return 0;
        }
        if (begin == end) {
            return heights[begin];
        }
        
        int minHeightIndex = begin + (end - begin) / 2;
        for (int i = begin; i <= end; i++) {
            if (heights[i] < heights[minHeightIndex]) {
                minHeightIndex = i;
            }
        }
        return max(max(divideAndConquer(heights, begin, minHeightIndex - 1), divideAndConquer(heights, minHeightIndex + 1, end)), heights[minHeightIndex] * (end - begin + 1));
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        return divideAndConquer(heights, 0, heights.size() - 1);
    }
};
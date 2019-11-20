class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int size = height.size();
        for (int i = 0; i < size; i++) {
            int leftMax = 0, rightMax = 0;
            for (int j = 0; j <= i; j++) {
                if (leftMax < height[j]) {
                    leftMax = height[j];
                }
            }
            for (int j = i; j < size; j++) {
                if (rightMax < height[j]) {
                    rightMax = height[j];
                }
            }
            water += (min(leftMax, rightMax) - height[i]);
        }
        return water;
    }
};
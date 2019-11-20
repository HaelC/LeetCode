class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        right_max[size-1] = height[size-1];
        
        for (int i = 1; i < size; i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int water = 0;
        for (int i = 0; i < size; i++) {
            water += min(left_max[i], right_max[i]) - height[i];
        }
        return water;
    }
};
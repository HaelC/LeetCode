class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), left = n, right = -1;
        
        for (int i = 0; i < n; i++) {
            if (s.empty() || nums[i] >= nums[s.top()]) {
                s.push(i);
            }
            else {
                while (!s.empty() && nums[s.top()] > nums[i]) {
                    left = min(left, s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty() || nums[i] <= nums[s.top()]) {
                s.push(i);
            }
            else {
                while (!s.empty() && nums[s.top()] < nums[i]) {
                    right = max(right, s.top());
                    s.pop();
                }
                s.push(i);
            }
        }
        
        return right == -1 ? 0 : right - left + 1;
    }
};
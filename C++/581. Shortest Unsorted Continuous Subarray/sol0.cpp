class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int begin = copy.size(), end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i]) {
                begin = min(begin, i);
                end = max(end, i);
            }
        }
        return end == -1 ? 0 : end - begin + 1;
    }
};
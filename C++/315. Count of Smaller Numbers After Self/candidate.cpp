class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    cnt++;
                }
            }
            result.push_back(cnt);
        }
        return result;
    }
};
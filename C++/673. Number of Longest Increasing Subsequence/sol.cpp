class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), longestLength = 0, result = 0;
        vector<int> lis(n, 1);
        vector<int> cnt(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (lis[j] + 1 == lis[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            longestLength = max(longestLength, lis[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (lis[i] == longestLength) {
                result += cnt[i];
            }
        }
        
        return result;
    }
};
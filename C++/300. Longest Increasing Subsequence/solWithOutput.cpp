class Solution {
private:
    void output(vector<int>& nums, vector<int>& position, int index) {
        vector<int> seq{nums[index]};
        while (position[index] != index) {
            index = position[index];
            seq.insert(seq.begin(), nums[index]);
        }
        for (auto i : seq) {
            cout << i << " ";
        }
        cout << endl;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
        
        vector<int> dp(nums.size());
        vector<int> position(nums.size());
        dp[0] = 1;
        position[0] = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            int max = 1;
            position[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (max < dp[j] + 1) {
                        max = dp[j] + 1;
                        position[i] = j;
                    }
                }
            }
            dp[i] = max;
        }
        
        int result = 0, index = -1;
        for (int i = 0; i < dp.size(); i++) {
            if (result < dp[i]) {
                result = dp[i];
                index = i;
            }
        }
        
        output(nums, position, index);
        
        return result;
    }
};
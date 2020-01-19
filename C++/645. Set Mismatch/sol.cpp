class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> sequence(n, 0);
        vector<int> result;
        for (int num : nums) {
            sequence[num - 1]++;
            if (sequence[num - 1] == 2) {
                result.push_back(num);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (sequence[i] == 0) {
                result.push_back(i + 1);
                break;
            }
        }
        
        return result;
    }
};
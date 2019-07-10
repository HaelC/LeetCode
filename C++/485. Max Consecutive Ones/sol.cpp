class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, consecutive = 0, maxConsec = 0;
        while (i < nums.size()) {
            if (nums[i]) {
                consecutive = 1;
                int k = i + 1;
                while (k < nums.size() && nums[k]) {
                    ++k;
                    ++consecutive;
                }
                if (consecutive > maxConsec)
                    maxConsec = consecutive;
                i = k + 1;
            }
            else {
                ++i;
            }
        }
        return maxConsec;
    }
};
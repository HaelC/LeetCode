class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num : nums) {
            hashset.insert(num);
        }
        
        int longest = 0;
        for (int num : hashset) {
            if (hashset.count(num - 1) == 0) {
                int current = 1;
                while (hashset.count(num + 1) > 0) {
                    num++;
                    current++;
                }
                longest = max(longest, current);
            }
        }
        return longest;
    }
};
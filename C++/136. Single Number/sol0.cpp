class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (auto p : count) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return 0;
    }
};
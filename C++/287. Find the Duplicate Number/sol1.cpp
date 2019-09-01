class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto num: nums) {
            if (hashset.count(num) > 0)
                return num;
            hashset.insert(num);
        }
        return 0;
    }
};
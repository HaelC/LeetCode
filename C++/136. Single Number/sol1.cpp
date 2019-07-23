class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset1;
        unordered_set<int> hashset2;
        for (auto num : nums) {
            if (hashset1.count(num) > 0)
                hashset2.insert(num);
            else
                hashset1.insert(num);
        }
        for (auto num : nums) {
            if (hashset2.count(num) <= 0)
                return num;
        }
        return 0;
    }
};
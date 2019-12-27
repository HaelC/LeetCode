class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int setSum = 0;
        unordered_set<int> hashset;
        for (int num : nums) {
            if (hashset.count(num) == 0) {
                hashset.insert(num);
                setSum += num;
            }
            sum += num;
        }
        return 2 * setSum - sum;
    }
};
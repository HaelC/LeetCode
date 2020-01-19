class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        long setSum = 0, arraySum = 0;
        for (int num : nums) {
            arraySum += num;
            hashset.insert(num);
        }
        
        for (int num : hashset) {
            setSum += num;
        }
        
        return (setSum * 3 - arraySum) / 2;
    }
};
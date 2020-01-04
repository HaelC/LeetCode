class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        
        for (int num : nums) {
            hashmap[num]++;
            if (hashmap[num] > n / 2) {
                return num;
            }
        }
        return -1;
    }
};
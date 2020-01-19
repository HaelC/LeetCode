class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int result = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += (nums[i] == 1) ? 1 : -1;
            if (count == 0) {
                result = i + 1;
            }
            else if (hashmap.count(count) > 0) {
                result = max(result, i - hashmap[count]);
            }
            else {
                hashmap[count] = i;
            }
        }
        return result;
    }
};
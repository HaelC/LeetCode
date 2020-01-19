class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hashmap;
        int result = 0;
        for (int num : arr) {
            hashmap[num] = hashmap[num - difference] + 1;
            result = max(hashmap[num], result);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        vector<int> result;
        for (int num : nums1) {
            hashmap[num]++;
        }
        for (int num : nums2) {
            if (hashmap[num] > 0) {
                hashmap[num]--;
                result.push_back(num);
            }
        }
        return result;
    }
};
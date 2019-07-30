class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap1;
        for (auto num : nums1) {
            if (hashmap1.count(num) > 0) {
                hashmap1[num]++;
            }
            else
                hashmap1[num] = 1;
        }
        vector<int> result;
        unordered_map<int, int> hashmap2;
        for (auto num : nums2) {
            if (hashmap2.count(num) > 0) {
                hashmap2[num]++;
            }
            else
                hashmap2[num] = 1;
            if (hashmap1.count(num) > 0 && hashmap2[num] <= hashmap1[num])
                result.push_back(num);
        }
        return result;
    }
};
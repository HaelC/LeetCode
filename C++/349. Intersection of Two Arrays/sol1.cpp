class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        unordered_set<int> inter;
        for (auto num : nums1) {
            hashset.insert(num);
        }
        for (auto num : nums2) {
            if (hashset.count(num))
                inter.insert(num);
        }
        vector<int> result(inter.begin(), inter.end());
        return result;
    }
};
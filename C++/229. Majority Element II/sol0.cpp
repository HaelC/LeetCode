class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 3;
        unordered_map<int, int> hashmap;
        vector<int> result;
        for (int num : nums) {
            hashmap[num]++;
        }
        for (auto p : hashmap) {
            if (p.second > threshold) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};
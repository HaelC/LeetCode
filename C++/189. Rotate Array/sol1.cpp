class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i = 0; i < k; ++i) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};
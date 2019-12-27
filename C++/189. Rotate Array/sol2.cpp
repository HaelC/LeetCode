class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tail(nums.begin(), nums.begin() + nums.size() - k);
        vector<int> head(nums.begin() + nums.size() - k, nums.end());
        head.insert(head.end(), tail.begin(), tail.end());
        nums = head;
    }
};
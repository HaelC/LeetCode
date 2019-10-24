class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int left = i + 1, right = size - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    vector row{-target, nums[left], nums[right]};
                    result.push_back(row);
                    // left++;
                    // right--;
                    while (left < size - 1 && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while (right > 0 && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return result;
    }
};
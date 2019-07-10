class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return vector<int>{l+1, r+1};
            else if (sum > target)
                r--;
            else
                l++;
        }
        return v;
    }
};
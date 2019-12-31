class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.empty()) {
            if (lower == upper) {
                result.push_back(to_string(lower));
            }
            else {
                result.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return result;
        }
        
        long last = (long)lower - 1;
        
        for (int num : nums) {
            if (num == last + 2) {
                result.push_back(to_string(last + 1));
            }
            else if (num > last + 2) {
                result.push_back(to_string(last + 1) + "->" + to_string(num - 1));
            }
            last = num;
        }
        
        if (last == upper - 1) {
            result.push_back(to_string(upper));
        }
        else if (last < upper - 1) {
            result.push_back(to_string(last + 1) + "->" + to_string(upper));
        }
        return result;
    }
};
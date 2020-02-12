class Solution {
private:
    int quadratic(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
    
    vector<int> processLinear(vector<int>& nums, int b, int c) {
        int n = nums.size();
        vector<int> result(n, 0);
        if (b > 0) {
            for (int i = 0; i < n; i++) {
                result[i] = nums[i] * b + c;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                result[i] = nums[n - i - 1] * b + c;
            }
        }
        return result;
    }
    
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            return processLinear(nums, b, c);
        }
        
        double axis = - b / (2.0 * a);
        int n = nums.size();
        vector<int> result;
        
        int mid = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i] - axis) < abs(nums[mid] - axis)) {
                mid = i;
            }
        }
        
        result.push_back(quadratic(nums[mid], a, b, c));
        int left = mid - 1, right = mid + 1;
        while (left >= 0 && right < n) {
            if (abs(nums[left] - axis) <= abs(nums[right] - axis)) {
                result.push_back(quadratic(nums[left--], a, b, c));
            }
            else {
                result.push_back(quadratic(nums[right++], a, b, c));
            }
        }
        while (left >= 0) {
            result.push_back(quadratic(nums[left--], a, b, c));
        }
        while (right < n) {
            result.push_back(quadratic(nums[right++], a, b, c));
        }
        
        if (a < 0) {
            reverse(result.begin(), result.end());
        }
        return result;
    }
};
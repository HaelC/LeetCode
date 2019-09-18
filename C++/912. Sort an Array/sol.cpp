class Solution {
private:
    vector<int> mergeSort(vector<int> nums) {
        if (nums.size() <= 1) return nums;
        int mid = (nums.size() - 1) / 2;
        vector<int> leftVec(nums.begin(), nums.begin() + 1 + mid);
        vector<int> rightVec(nums.begin() + mid + 1, nums.end());
        vector<int> left = mergeSort(leftVec);
        vector<int> right = mergeSort(rightVec);
        return merge(left, right);
    }
    
    vector<int> merge(vector<int> left, vector<int> right) {
        int leftSize = left.size(), rightSize = right.size();
        vector<int> result(leftSize + rightSize);
        int leftIndex = 0, rightIndex = 0, index = 0;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (left[leftIndex] <= right[rightIndex]) {
                result[index++] = left[leftIndex++];
            }
            else {
                result[index++] = right[rightIndex++];
            }
        }
        
        while (leftIndex < leftSize) {
            result[index++] = left[leftIndex++];
        }
        
        while (rightIndex < rightSize) {
            result[index++] = right[rightIndex++];
        }
        
        return result;
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums);
    }
};
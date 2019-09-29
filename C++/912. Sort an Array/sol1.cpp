class Solution {
private:
    void quickSort(vector<int>& nums, int p, int r) {
        if (p < r) {
            int q = partition(nums, p, r);
            quickSort(nums, p, q - 1);
            quickSort(nums, q + 1, r);
        }
    }
    
    int partition(vector<int>& nums, int p, int r) {
        int pivot = nums[r];
        int i = p;
        for (int j = p; j < r; ++j) {
            if (nums[j] < pivot) {
                int temp = nums[i];
                nums[i++] = nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[i];
        nums[i] = nums[r];
        nums[r] = temp;
        return i;
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
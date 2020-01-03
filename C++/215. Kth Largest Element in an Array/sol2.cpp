class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    int partition(vector<int>& nums, int p, int r) {
        int pivot = nums[r];
        int i = p;
        for (int j = p; j < r; j++) {
            if (nums[j] > pivot) {
                swap(nums, i, j);
                i++;
            }
        }
        swap(nums, i, r);
        return i;
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        
        int index = partition(nums, left, right);
        if (k == index) {
            return nums[k];
        }
        else if (k > index) {
            return quickSelect(nums, index + 1, right, k);
        }
        else {
            return quickSelect(nums, left, index - 1, k);
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};
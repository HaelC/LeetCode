// Heap sort
class Solution {
private:
    void buildMaxHeap(vector<int>& nums) {
        int heapSize = nums.size() - 1;
        for (int i = heapSize / 2; i >= 1; --i) {
            maxHeapify(nums, i, heapSize);
        }
    }
    
    // a bit different from the code in the textbook
    // with non-recursive way to max_heapify
    void maxHeapify(vector<int>& nums, int i, int heapSize) {
        int tempI = i;
        while (tempI <= heapSize / 2) {
            int left = 2 * tempI, right = 2 * tempI + 1;
            int largest = tempI;
            if (left <= heapSize && nums[left] > nums[tempI])
                largest = left;
            if (right <= heapSize && nums[right] > nums[largest])
                largest = right;
            if (largest == tempI)
                break;
            int temp = nums[tempI];
            nums[tempI] = nums[largest];
            nums[largest] = temp;
            tempI = largest;
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        // insert a useless element to the beginning of the vector
        // so that the index begins with 1
        nums.insert(nums.begin(), 0); 
        buildMaxHeap(nums);
        
        int heapSize = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 2; --i) {
            int temp = nums[1];
            nums[1] = nums[i];
            nums[i] = temp;
            maxHeapify(nums, 1, --heapSize);
        }

        // remove the useless element inserted at the beginning
        nums.erase(nums.begin());
        
        return nums;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index0 = -1, indexNon0 = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                index0 = i;
                break;
            }
        }
            
        if (index0 != -1) {
            for (int i = index0 + 1; i < nums.size(); ++i) {
                if (nums[i]) {
                    indexNon0 = i;
                    break;
                }
            }
        }
        
        if (index0 == -1 || indexNon0 == -1)
            return;
        
        while (indexNon0 < nums.size() && index0 < nums.size() && index0 < indexNon0) {
            nums[index0++] = nums[indexNon0];
            nums[indexNon0++] = 0;
            while (index0 < nums.size() && nums[index0] != 0)
                ++index0;
            if (indexNon0 < index0)
                indexNon0 = index0 + 1;
            while (indexNon0 < nums.size() && nums[indexNon0] == 0)
                ++indexNon0;
        }
    }
};
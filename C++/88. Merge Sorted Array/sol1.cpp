class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1, p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            }
            else {
                nums1[p--] = nums2[p2--];
            }
        }
        if (p2 >= 0) {
            for (int i = 0; i <= p2; i++) {
                nums1[i] = nums2[i];
            }
        }
    }
};
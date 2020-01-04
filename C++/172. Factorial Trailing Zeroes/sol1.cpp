class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0, temp = 0;
        while (n / 5 > 0) {
            temp = n / 5;
            count += temp;
            n = temp;
        }
        return count;
    }
};
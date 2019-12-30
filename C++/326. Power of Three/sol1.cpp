class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1162261467 (3^19) is the maximum power of three in integer.
        return n > 0 && 1162261467 % n == 0;
    }
};
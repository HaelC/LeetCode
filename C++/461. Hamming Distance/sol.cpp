class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        
        while (x || y) {
            result += (x & 1) ^ (y & 1);
            x = x >> 1;
            y = y >> 1;
        }
        return result;
    }
};
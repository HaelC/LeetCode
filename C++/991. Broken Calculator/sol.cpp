class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cnt = 0;
        while (Y > X) {
            Y = (Y % 2 == 0) ? Y / 2 : Y + 1;
            cnt++;
        }
        return cnt + X - Y;
    }
};
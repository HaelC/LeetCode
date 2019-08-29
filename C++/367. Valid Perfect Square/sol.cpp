class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid < num / mid)
                left = mid + 1;
            else if (mid > num / mid)
                right = mid - 1;
            else
                return (num % mid == 0);
        }
        return false;
    }
};
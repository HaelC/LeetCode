class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int left = 1, right = x, answer;
        while (left <= right) {
            //sqr = (left + right) / 2;
            int mid = left + (right - left) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid < x / mid) {
                left = mid + 1;
                answer = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return answer;
    }
};
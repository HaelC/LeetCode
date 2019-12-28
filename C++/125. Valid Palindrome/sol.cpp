class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < s.length() && !isalnum(s[left])) {
                left++;
            }
            while (right >= 0 && !isalnum(s[right])) {
                right--;
            }
            if (left < s.length() && right >= 0 && tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }
};
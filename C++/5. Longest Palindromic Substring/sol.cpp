class Solution {
private:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && (s[left] == s[right])) {
            left--;
            right++;
        }
        return right - left - 1;        // (right - 1) - (left + 1) + 1
    }
    
public:
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        int longest = 0, start = -1;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if (len > longest) {
                start = i - (len - 1) / 2;
                longest = len;
            }
        }
        return s.substr(start, longest);
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int n = s.length();
        int index = 0, longest = 1;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // begin with length of 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;               // string with length of 1 is always palindrome
        }
        
        for (int len = 2; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == len - 2) {
                    dp[i][j] = len;
                    if (len > longest) {
                        index = i;
                        longest = len;
                    }
                }
            }
        }
        return s.substr(index, longest);
    }
};
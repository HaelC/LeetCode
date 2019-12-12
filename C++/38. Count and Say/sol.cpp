class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n);
        dp[0] = "1";
        for (int i = 1; i < n; i++) {
            string prev = dp[i - 1];
            string cur = "";
            char prevNum = prev[0];
            int num = 0;
            for (char c : prev) {
                if (c == prevNum) {
                    num++;
                }
                else {
                    cur += to_string(num) + prevNum;
                    prevNum = c;
                    num = 1;
                }
            }
            cur += to_string(num) + prevNum;
            dp[i] = cur;
        }
        return dp[n-1];
    }
};
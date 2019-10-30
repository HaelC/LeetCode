// Reference
// https://www.youtube.com/watch?v=_nCsPn7_OgI&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=9
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.length();
        // int longest = 0;
        vector<vector<int>> table(length, vector<int>(length, 0));
        for (int j = 0; j < length; j++) {
            for (int i = 0; i < length - j; i++) {
                if (!j) {
                    table[i][i] = 1;
                }
                else {
                    if (s[i] == s[i+j]) {
                        table[i][i+j] = 2 + table[i+1][i+j-1];
                    }
                    else {
                        table[i][i+j] = max(table[i+1][i+j], table[i][i+j-1]);
                    }
                }
                /*
                if (table[i][i+j] > longest) {
                    longest = table[i][i+j];
                }
                */
            }
        }
        // return longest;
        return table[0][length-1];
    }
};
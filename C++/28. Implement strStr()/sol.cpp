class Solution {
public:
    int strStr(string haystack, string needle) {
        return stringMatch(haystack, needle);
    }
    
    int stringMatch(string &text, string &pattern) {
        int m = pattern.length(), n = text.length();
        if (!m) return 0;
        
        vector<int> auxi(m);
        createAuxiliary(auxi, pattern);
        
        int i = 0, j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                ++i;
                ++j;
            }
            if (j == m) 
                return i - j;
            else if (i < n && pattern[j] != text[i]) {
                if (j != 0)
                    j = auxi[j-1];
                else
                    ++i;
            }
        }
        return -1;
    }
    
    void createAuxiliary(vector<int> &a, string &pattern) {
        int len = 0;
        int m = a.size();
        a[0] = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                ++len;
                a[i] = len;
                ++i;
            }
            else {
                if (len != 0) {
                    len = a[len - 1];
                }
                else {
                    a[i] = 0;
                    ++i;
                }
            }
        }
    }
};
class Solution {
private:
    int insertions(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (s[i] == s[j]) {
            return insertions(s, i + 1, j - 1);
        }
        else {
            return min(insertions(s, i + 1, j), insertions(s, i, j - 1)) + 1;
        }
    }
    
public:
    int minInsertions(string s) {
        return insertions(s, 0, s.length() - 1);
    }
};
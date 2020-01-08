class Solution {
private:
    int insertions(string& s, vector<vector<int>>& mem, int i, int j) {
        if (i >= j) {
            mem[i][j] = 0;
            return 0;
        }
        if (mem[i][j] != -1) {
            return mem[i][j];
        }
        int result = -1;
        if (s[i] == s[j]) {
            result = insertions(s, mem, i + 1, j - 1);
            
        }
        else {
            result = 1 + min(insertions(s, mem, i + 1, j), insertions(s, mem, i, j - 1));
        }
        mem[i][j] = result;
        return result;
    }
    
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> mem(len, vector<int>(len, -1));
        return insertions(s, mem, 0, s.length() - 1);
    }
};
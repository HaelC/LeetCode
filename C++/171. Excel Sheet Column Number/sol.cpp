class Solution {
public:
    int titleToNumber(string s) {
        vector<int> map(26, 0);
        for (int i = 0; i < 26; i++) {
            map[i] = i + 1;
        }
        
        int result = 0;
        long base26 = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            result += map[s[i] - 'A'] * base26;
            base26 *= 26;
        }
        
        return result;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1;
        string result;
        int flag = 0;
        while (i >= 0) {
            string word;
            while (i >= 0 && s[i] == ' ')
                --i;
            while (i >= 0 && s[i] != ' ') {
                if (flag && !result.empty()) {
                    result += ' ';
                    flag = 0;
                }
                word = s[i] + word;
                --i;
            }
            result += word;
            flag = 1;
        }
        return result;
        
    }
};
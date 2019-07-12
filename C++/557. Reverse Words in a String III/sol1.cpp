class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j;
        string result = "";
        while (i < s.length()) {
            j = i;
            string word = "";
            while (j < s.length() && s[j] != ' ') {
                word = s[j] + word;
                ++j;
            }
            if (result.empty())
                result = word;
            else
                result = result + ' ' + word;
            i = j + 1;
        }
        return result;
    }
};
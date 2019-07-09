class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = "";
        
        int minStrLen = strs[0].length();
        for (auto &s : strs)
            if (s.length() < minStrLen)
                minStrLen = s.length();
        
        int i = 0;
        while (i < minStrLen) {
            char c = strs[0][i];
            int flag = 1;
            for (auto &s : strs)
                if (s[i] != c) {
                    flag = 0;
                    break;
                }
            if (flag) {
                ++i;
                prefix += c;
            }
            else
                break;
        }
        return prefix;
    }
};
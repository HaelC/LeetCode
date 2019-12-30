class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        int minStr = strs[0].length();
        for (string str : strs) {
            minStr = min(minStr, (int)str.length());
        }
        
        int i = 0;
        while (i < minStr) {
            char c = strs[0][i];
            for (string str : strs) {
                if (str[i] != c) {
                    return strs[0].substr(0, i);
                }
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};
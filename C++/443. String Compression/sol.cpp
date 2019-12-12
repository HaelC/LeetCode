class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) {
            return chars.size();
        }
        int i = 0, j = 0;
        while (i < chars.size()) {
            chars[j] = chars[i];
            int num = 0;
            while (i < chars.size() && chars[i] == chars[j]) {
                i++;
                num++;
            }
            
            if (num > 1) {
                string s = to_string(num);
                for (char c : s) {
                    chars[++j] = c;
                }
            }
            j++;
        }
        return j;
    }
};
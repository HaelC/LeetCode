class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0, result = 0;
        for (char c : S) {
            if (c == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                }
                else {
                    result++;
                }
            }
        }
        result += open;
        return result;
    }
};
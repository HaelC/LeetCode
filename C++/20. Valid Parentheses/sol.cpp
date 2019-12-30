class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            }
            else {
                if (parentheses.empty()) {
                    return false;
                }
                if ((c == ')' && parentheses.top() != '(')
                    || (c == ']' && parentheses.top() != '[')
                    || (c == '}' && parentheses.top() != '{')) {
                    return false;
                }
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        int len = s.length();
        if (len % 2)
            return false;
        
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                parentheses.push(s[i]);
            else {
                if (parentheses.empty())
                    return false;
                if (s[i] == ')') {
                    if (parentheses.top() != '(')
                        return false;
                    parentheses.pop();
                }
                else if (s[i] == ']') {
                    if (parentheses.top() != '[')
                        return false;
                    parentheses.pop();
                }
                else {
                    if (parentheses.top() != '{')
                        return false;
                    parentheses.pop();
                }
            }
        }
        if (parentheses.empty())
            return true;
        else
            return false;
    }
};
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        string result = "";
        for (int i = expression.length() - 1; i >= 0; i--) {
            char c = expression[i];
            if (!s.empty() && s.top() == '?') {
                s.pop();                    // '?'
                char first = s.top();
                s.pop();
                s.pop();                    // ':'
                char second = s.top();
                s.pop();
                if (c == 'T') {
                    s.push(first);
                }
                else {
                    s.push(second);
                }
            }
            else {
                s.push(c);
            }
        }
        result += s.top();
        return result;
    }
};
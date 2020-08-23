class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        
        for (char c : S) {
            if (c == '#' && !s.empty()) {
                s.pop();
            }
            else if (c != '#') {
                s.push(c);
            }
        }
        
        for (char c : T) {
            if (c == '#' && !t.empty()) {
                t.pop();
            }
            else if (c != '#') {
                t.push(c);
            }
        }
        
        if (s.size() != t.size()) {
            return false;
        }
        while (!s.empty()) {
            if (s.top() != t.top()) {
                return false;
            }
            s.pop();
            t.pop();
        }
        return true;
    }
};
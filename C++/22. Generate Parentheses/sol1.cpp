// non-recursive solution, which might be a bit unintelligble
class Solution {
private:
    struct curOpenClose {
        string parentheses;
        int open;
        int close;
    };
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        struct curOpenClose init = {"", 0, 0};
        stack<struct curOpenClose> s;
        s.push(init);
        
        while (!s.empty()) {
            struct curOpenClose cur = s.top();
            s.pop();
            string parentheses = cur.parentheses;
            if (parentheses.length() == 2 * n) {
                result.push_back(parentheses);
            }
            else {
                if (cur.open < n) {
                    struct curOpenClose cur1 = {parentheses + "(", cur.open + 1, cur.close};
                    s.push(cur1);
                }
                if (cur.close < cur.open) {
                    struct curOpenClose cur2 = {parentheses + ")", cur.open, cur.close + 1};
                    s.push(cur2);
                }
            }
        }
        return result;
    }
};
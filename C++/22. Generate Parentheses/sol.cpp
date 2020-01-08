class Solution {
private:
    void backtracking(vector<string>& parentheses, string current, int open, int n) {
        if (current.length() == n * 2) {
            parentheses.push_back(current);
            return;
        }
        if (open < n) {
            backtracking(parentheses, current + '(', open + 1, n);
        }
        if (open * 2 > current.length()) {
            backtracking(parentheses, current + ')', open, n);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        backtracking(parentheses, "", 0, n);
        return parentheses;
    }
};
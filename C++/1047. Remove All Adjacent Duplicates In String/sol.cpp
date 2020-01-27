class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char c : S) {
            if (st.empty() || c != st.top()) {
                st.push(c);
            }
            else {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
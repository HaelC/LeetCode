// Recursive way
class Solution {
private:
    void reverseHelper(vector<char>& s, int i, int j) {
        if (i >= j)
            return;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverseHelper(s, i+1, j-1);
    }
    
public:
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size() - 1);
    }
};
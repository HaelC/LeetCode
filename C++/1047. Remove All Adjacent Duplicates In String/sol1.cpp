class Solution {
public:
    string removeDuplicates(string S) {
        if (S.length() < 2) {
            return S;
        }
        
        int left = 0, right = 1;
        while (right < S.length()) {
            if (left >= 0 && S[left] == S[right]) {
                left--;
            }
            else {
                S[++left] = S[right];
            }
            right++;
        }
        return S.substr(0, left + 1);
    }
};
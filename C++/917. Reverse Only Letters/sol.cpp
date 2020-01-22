class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.length();
        int left = 0, right = len - 1;
        while (left < right) {
            if (!isalpha(S[left])) {
                left++;
            }
            else if (!isalpha(S[right])) {
                right--;
            }
            else {
                char temp = S[left];
                S[left] = S[right];
                S[right] = temp;
                left++;
                right--;
            }
        }
        return S;
    }
};
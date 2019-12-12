class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashmap;
        for (char c : s) {
            hashmap[c]++;
        }
        
        int len = 0, oddMax = 0;
        for (auto it : hashmap) {
            if (it.second % 2 == 0) {
                len += it.second;
            }
            else {
                oddMax = max(oddMax, it.second);
                len += it.second - 1;
            }
        }
        if (oddMax) {
            len++;
        }
        return len;
    }
};
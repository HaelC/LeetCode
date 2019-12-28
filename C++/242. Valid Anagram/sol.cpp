class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> freqs(26, 0);
        for (char c : s) {
            freqs[c - 'a']++;
        }
        for (char c : t) {
            freqs[c - 'a']--;
        }
        for (int f : freqs) {
            if (f) {
                return false;
            }
        }
        return true;
    }
};
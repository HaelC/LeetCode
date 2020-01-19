bool stringSort(string s1, string s2) {
    return s1.length() > s2.length() || (s1.length() == s2.length() && s1 < s2);
}

class Solution {
private:
    bool isSubsequence(string s, string t) {
        int indexS = 0, indexT = 0;
        while (indexS < s.length()) {
            if (s[indexS] == t[indexT]) {
                indexS++;
                indexT++;
                if (indexT == t.length()) {
                    return true;
                }
            }
            else {
                indexS++;
            }
        }
        return false;
    }
    
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), stringSort);
        for (string t : d) {
            if (isSubsequence(s, t)) {
                return t;
            }
        }
        return "";
    }
};
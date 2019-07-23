class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int length = s.length();
        unordered_map<char, char> hashmap;
        unordered_set<char> used;
        for (int i = 0; i < length; ++i) {
            if (hashmap.count(s[i]) > 0 && hashmap[s[i]] != t[i])
                return false;
            else if (hashmap.count(s[i]) <= 0 && used.count(t[i]) > 0) {
                return false;
            }
            else if (hashmap.count(s[i]) <= 0) {
                hashmap[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};
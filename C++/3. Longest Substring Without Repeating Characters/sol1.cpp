class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, current = 0;
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); i++) {
            if (hashmap.count(s[i]) == 0 || hashmap[s[i]] < i - current) {
                current++;
                longest = max(current, longest);
            }
            else {
                current = i - hashmap[s[i]];
            }
            hashmap[s[i]] = i;
        }
        return longest;
    }
};
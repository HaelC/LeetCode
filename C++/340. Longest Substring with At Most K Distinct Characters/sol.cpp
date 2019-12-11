class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.length() <= k) return s.length();
        
        unordered_map<char, int> hashmap;
        int longest = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            hashmap[s[i]]++;
            while (hashmap.size() > k) {
                hashmap[s[start]]--;
                if (hashmap[s[start]] == 0) {
                    hashmap.erase(s[start]);
                }
                start++;
            }
            longest = max(i - start + 1, longest);
        }
        return longest;
    }
};
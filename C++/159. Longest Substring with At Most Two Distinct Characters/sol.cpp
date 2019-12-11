class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() <= 2) return s.length();
        unordered_map<char, int> hashmap;
        int cnt = 0, start = 0, longest = 0;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            hashmap[s[i]]++;
            if (hashmap[s[i]] == 1) {
                cnt++;
            }
            while (cnt > 2) {
                hashmap[s[start]]--;
                if (hashmap[s[start]] == 0) {
                    cnt--;
                }
                start++;
            }
            if (i - start + 1 > longest) {
                longest = i - start + 1;
                left = start;
                right = i;
            }
        }
        return longest;
    }
};
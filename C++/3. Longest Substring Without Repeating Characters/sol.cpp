class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashmap(256, -1);
        int longest = 0;
        int leftIndex = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (hashmap[s[i]] > leftIndex)
                leftIndex = hashmap[s[i]];
            hashmap[s[i]] = i;
            longest = max(longest, i - leftIndex);
        }
        return longest;
    }
};